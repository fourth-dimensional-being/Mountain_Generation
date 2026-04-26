CMAKE_MINIMUM_REQUIRED(VERSION 4.1.0)
Project(Mountain_Generator)

set(SDL3dir ${PROJECT_SOURCE_DIR}/Dependencies/SDL3)
set(SDL3imagedir ${PROJECT_SOURCE_DIR}/Dependencies/SDL3_Image)
set(CMAKE_PREFIX_PATH ${SDL3dir} ${SDL3imagedir})

find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_image CONFIG REQUIRED)

add_executable(Generator main.cpp Generator.cpp Renderer.cpp)

target_link_libraries(Generator SDL3::SDL3 SDL3_image::SDL3_image)

add_custom_command(TARGET Generator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3dir}/bin/SDL3.dll"
        $<TARGET_FILE_DIR:Generator>)
add_custom_command(TARGET Generator POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3imagedir}/bin/SDL3_image.dll"
        $<TARGET_FILE_DIR:Generator>)
