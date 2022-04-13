#
# Copyright 2022 Adobe
# All Rights Reserved.
#
# NOTICE: Adobe permits you to use, modify, and distribute this file in
# accordance with the terms of the Adobe license agreement accompanying
# it.
#

# Set the name of your project here
set(DOXYGEN_PROJECT_NAME Foo)

cmake_minimum_required(VERSION 3.16)
project(${DOXYGEN_PROJECT_NAME}Docs)

find_package(Doxygen REQUIRED)

# Space-separated list of public include folders used by this project. We could also get that from
# our CMake targets, but this works well enough.
set(DOXYGEN_INCLUDE_PATHS include)

# Space-separated list of input files/folders containing documentation.
set(DOXYGEN_INPUT
    include
    src
)
list(JOIN DOXYGEN_INPUT " " DOXYGEN_INPUT)

# Exclude those folders from Doxygen documentation.
set(DOXYGEN_EXCLUDE
    # src/somefolder/
    # src/somefile
)
list(JOIN DOXYGEN_EXCLUDE " " DOXYGEN_EXCLUDE)

# If you want to use a different .md file as the main Doxygen page. Do not forget to include it in
# the DOXYGEN_INPUT list.
set(DOXYGEN_MDFILE_AS_MAINPAGE src/README.md)

# To customize the layout of the Doxygen website, follow instructions here:
# https://www.doxygen.nl/manual/customize.html
#
# 1. Run `doxygen -l` in your terminal;
# 2. Set DOXYGEN_LAYOUT_FILE to the generated DoxygenLayout.xml;
# 3. Add DoxygenLayout.xml to your git repo and customize its content.
set(DOXYGEN_LAYOUT_FILE "")

set(DOXYGEN_WORKING_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)
set(DOXYGEN_OUTPUT_DIR ${CMAKE_BINARY_DIR} CACHE PATH "Output base dir for doxygen documentation")
set(DOXYGEN_OUTPUT_HTML html CACHE STRING "Output subdir for doxygen html")
set(DOXYFILE_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

# Replace variables inside @@ with the current values
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR}) # Doxygen won't create this for us

add_custom_target(doc
                  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
                  WORKING_DIRECTORY ${DOXYGEN_WORKING_DIR}
                  COMMENT "Generating docs")
