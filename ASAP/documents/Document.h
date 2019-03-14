#ifndef __ASAP_DOCUMENTS_DOCUMENT__
#define __ASAP_DOCUMENTS_DOCUMENT__

#include "asaplib_export.h"

#include <qrect.h>

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <multiresolutionimageinterface/MultiResolutionImage.h>

class PluginInformation
{
	
};



typedef std::unordered_map<uint32_t, std::unordered_map<int32_t, std::unordered_map<int32_t, uchar>>> CoverageMap;

struct TileInformation
{
	const uint64_t						tile_size;
	uint64_t							last_level;
	uint64_t							last_render_level;
	QRect								last_FOV;
	std::vector<float>					downsamples;
	std::vector<std::vector<uint64_t>>	dimensions;
	CoverageMap							coverage;
};

namespace ASAP::Documents
{
	class Document
	{
		public:
			Document(const std::string& filepath, const std::string& factory = "default");

			const std::string& GetFilepath(void);
			std::weak_ptr<MultiResolutionImage> GetImage(void);

			PluginInformation* GetPluginInformation(const std::string& plugin);
			bool HasPluginInformation(const std::string& plugin);
			void SetPluginInformation(const std::string& plugin, PluginInformation* information, const bool allow_override = false);

		private:
			std::string								m_filepath_;
			std::shared_ptr<MultiResolutionImage>	m_image_;
			std::unordered_map<std::string, std::unique_ptr<PluginInformation>> m_plugin_information_;
	};
}
#endif // __ASAP_DOCUMENTS_DOCUMENT__