<<<<<<< HEAD
# Install script for directory: /home/judith/Dokumente/Uni/final_raytracer
=======
# Install script for directory: /home/valentina/final_raytracer
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a

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
  set(CMAKE_INSTALL_SO_NO_EXE "1")
<<<<<<< HEAD
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
=======
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
<<<<<<< HEAD
  include("/home/judith/Dokumente/Uni/final_raytracer/build/external/glfw-3.2.1/cmake_install.cmake")
  include("/home/judith/Dokumente/Uni/final_raytracer/build/framework/cmake_install.cmake")
  include("/home/judith/Dokumente/Uni/final_raytracer/build/source/cmake_install.cmake")
=======
  include("/home/valentina/final_raytracer/build/external/glfw-3.2.1/cmake_install.cmake")
  include("/home/valentina/final_raytracer/build/framework/cmake_install.cmake")
  include("/home/valentina/final_raytracer/build/source/cmake_install.cmake")
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
file(WRITE "/home/judith/Dokumente/Uni/final_raytracer/build/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "/home/valentina/final_raytracer/build/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> 103048cf0f4e2f0863f42ad307412c7059044d8a
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
