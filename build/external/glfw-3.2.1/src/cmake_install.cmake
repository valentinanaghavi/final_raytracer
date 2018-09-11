<<<<<<< HEAD
# Install script for directory: /home/IN/wobi3451/final_raytracer/external/glfw-3.2.1/src
=======
<<<<<<< HEAD
# Install script for directory: /home/judith/Dokumente/Uni/final_raytracer/external/glfw-3.2.1/src
=======
# Install script for directory: /home/valentina/final_raytracer/external/glfw-3.2.1/src
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
<<<<<<< HEAD
  set(CMAKE_INSTALL_SO_NO_EXE "0")
=======
  set(CMAKE_INSTALL_SO_NO_EXE "1")
<<<<<<< HEAD
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
<<<<<<< HEAD
=======
=======
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
>>>>>>> 12364cb1d189c472b8070b099e08b29085803790
endif()

