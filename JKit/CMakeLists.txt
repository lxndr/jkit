set (JKIT_SOURCES
		Core/String.cpp
		Core/Exception.cpp
		Core/ObjectProperty.cpp
		Core/Object.cpp)

if (UNIX)
	set (JKIT_SOURCES ${JKIT_SOURCES}
			Core/Detail/Posix/Exception.cpp
			Core/Detail/Posix/LocalFile.cpp)
endif ()


add_library (jkit ${JKIT_SOURCES})
