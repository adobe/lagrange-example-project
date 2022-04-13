# Documentation

0. Install Doxygen on your machine:
    - On macOS, using [Homebrew](https://brew.sh/)
        ```
        brew install doxygen
        ```
    - On Windows, using [Chocolatey](https://chocolatey.org/):
        ```
        choco install -y doxygen.install
        ```
    - On Linux, using your distribution's package manager.

1. Edit the `docs/CMakeLists.txt` based on your project specifications (project name, source folders, desired layout, etc.).

2. Compile the Doxygen project using CMake:
    - Either by compiling the subfolder `docs/` directly:
        ```
        cd lagrange-project/docs
        mkdir build
        cd build
        cmake ..
        make doc
        ```
    - Or enabling the `FOO_BUILD_DOCUMENTATION` CMake option in the parent project:
        ```
        cd lagrange-project
        mkdir build
        cd build
        cmake -DFOO_BUILD_DOCUMENTATION=ON ..
        make doc
        ```

3. Open the generated html documentation:
    ```
    firefox html/index.html
    ```
