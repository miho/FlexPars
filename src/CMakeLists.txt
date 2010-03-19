
# add all .cpp files to project (stored in "raidmonitor_SRCS" variable")

# and finally an resource file
set(_SRCS
	Object.cpp
	StreamObject.cpp
	TagElement.cpp
	Tag.cpp
	File.cpp
	IntegerElement.cpp
	DoubleElement.cpp
	StringElement.cpp
	HeaderTag.cpp
	DoubleField.cpp
	#test.cpp
	)


include_directories(
			../include
			${CMAKE_CURRENT_BINARY_DIR}
			)

ADD_LIBRARY( flexpars SHARED ${_SRCS} )
ADD_LIBRARY( flexpars-static STATIC ${_SRCS} )

# give the static version the same output name as the shared one
set_target_properties(flexpars-static PROPERTIES OUTPUT_NAME flexpars)

#target_link_libraries( flexpars
			#${CMAKE_CURRENT_BINARY_DIR}
#                        )

install(TARGETS flexpars DESTINATION lib${LIB_SUFFIX}/flexpars)
install(TARGETS flexpars-static DESTINATION lib${LIB_SUFFIX}/flexpars)
INSTALL(DIRECTORY ../include/ DESTINATION include/flexpars)
