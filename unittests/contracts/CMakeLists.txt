# will be implictly used for any compilation unit if not overrided by SYSTEM_INCLUDE_FOLDERS parameter
# these directories go as -isystem <dir> to avoid warnings from code of third-party libraries

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/picoio.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/picoio.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/picoio.msig/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/picoio.msig/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/picoio.system/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/picoio.system/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/picoio.token/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/picoio.token/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/picoio.wrap/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/picoio.wrap/)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.6.0-rc3/picoio.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.6.0-rc3/picoio.bios/)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/old_versions/v1.7.0-develop-preactivate_feature/picoio.bios/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/old_versions/v1.7.0-develop-preactivate_feature/picoio.bios/)
