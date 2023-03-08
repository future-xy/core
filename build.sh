mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=`pwd`/install -DTRITON_THIRD_PARTY_REPO_TAG=r22.08 -DTRITON_COMMON_REPO_TAG=r22.08 -DTRITON_CORE_HEADERS_ONLY=OFF ..
cmake --build . --target install -j$(nproc)