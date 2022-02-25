python_root_dir=/root/miniconda3/envs/tiger/
python_version=3.8

cmake \
    -DWRAP_MULTIRESOLUTIONIMAGEINTERFACE_PYTHON=TRUE \
    -DBUILD_MULTIRESOLUTIONIMAGEINTERFACE_VSI_SUPPORT=TRUE  \
    -DDCMTKJPEG_INCLUDE_DIR=/root \
    -DDCMTKJPEG_LIBRARY=/usr/lib/libijg8.so \
    -DPugiXML_INCLUDE_DIR=/root/pugixml-1.9/src/ \
    -DOPENSLIDE_INCLUDE_DIR=/usr/include/openslide \
    -DPYTHON_DEBUG_LIBRARY=${python_root_dir}/lib/libpython${python_ver}.so \
    -DPYTHON_LIBRARY_DEBUG=${python_root_dir}/lib/libpython${python_ver}.so \
    -DPYTHON_LIBRARY=${python_root_dir}/lib/libpython${python_ver}.so \
    -DPYTHON_INCLUDE_DIR=${python_root_dir}/include/python${python_ver} \
    -DPYTHON_EXECUTABLE=${python_root_dir}/bin/python${python_ver} \
    -DPYTHON_NUMPY_INCLUDE_DIR=${python_root_dir}/lib/python${python_ver}/site-packages/numpy/core/include \
    -DCMAKE_INSTALL_PREFIX=/root/install \
    ../src
