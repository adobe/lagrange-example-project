# Lagrange Example Project

An example project that uses [Lagrange](https://github.com/adobe/lagrange). To get started, click on
["Use this template"](template) on GitHub, then go through the steps below, changing paths to your
project name.

[template]: https://docs.github.com/en/repositories/creating-and-managing-repositories/creating-a-repository-from-a-template

## Usage

0. Requirements

    - [CMake 3.20 or later](https://cmake.org/download). On Unix, CMake installed from `apt` can be
      outdated. Check with `cmake --version`.
    - Command line (Unix) or Powershell/Git Bash (Windows).

1. Clone the repository:

    ```bash
    git clone https://github.com/adobe/lagrange-example-project.git
    ```

2. Setup build:

    ```bash
    cd <lagrange-example-project>
    mkdir build
    cd build
    cmake ..
    ```

    By default, this will generate a Visual Studio project on Windows, and Unix Makefiles on OSX and
    Linux. If you wish to use XCode on Mac, use `cmake -G "Xcode" ..` instead.

3. Select Lagrange features

    You can browse Lagrange options to enable in Lagrange's `LagrangeOptions.cmake.sample` or by
    running `cmake-gui .`. Once you're done, press `Configure` and then `Generate`. In your
    project's `CMakeLists.txt`, include the modules you want by calling `lagrange_include_modules()`
    after including Lagrange.

4. Build

    ```bash
    cmake --build .
    ```

    Or open the Visual Studio/XCode project with `cmake --open .`

## Documentation

Please check the [`docs/`](docs/) folder for instructions on how to compile Doxygen documentation
for this project.

## Contributing

Contributions are welcomed! Read the [Contributing Guide](./.github/CONTRIBUTING.md) for more
information.

## Licensing

This example project is licensed under the MIT license. See [LICENSE](LICENSE) for more information.
