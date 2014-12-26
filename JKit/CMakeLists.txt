set (JKIT_SOURCES
		Core/Application.cpp
		Core/String.cpp
		Core/Exception.cpp
		Core/Stream.cpp
		Core/FileStream.cpp
		Core/MemoryStream.cpp
		Core/ObjectProperty.cpp
		Core/Object.cpp)

if (UNIX)
	set (JKIT_SOURCES ${JKIT_SOURCES}
			Core/Detail/Posix/Exception.cpp
			Core/Detail/Posix/LocalFile.cpp
			Core/Detail/Posix/FileStream.cpp)
elseif (WIN32)
	set (JKIT_SOURCES ${JKIT_SOURCES}
			Core/Detail/Windows/Exception.cpp
			Core/Detail/Windows/LocalFile.cpp
			Core/Detail/Windows/FileStream.cpp
			Core/Detail/Windows/Utils.cpp)
endif ()


add_library (jkit ${JKIT_SOURCES})
