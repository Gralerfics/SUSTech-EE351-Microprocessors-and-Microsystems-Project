cmake_minimum_required(VERSION 3.10)

project(project)
set(CMAKE_CXX_STANDARD 14)

# file(GLOB LVGL_HEADERS
#     "3rdparty/lvgl/*.h"
# )

include_directories(
    3rdparty
    3rdparty/lvgl
    3rdparty/lvgl/porting
    3rdparty/lvgl/demos
    3rdparty/lvgl/demos/benchmark
    3rdparty/lvgl/demos/keypad_encoder
    3rdparty/lvgl/demos/music
    3rdparty/lvgl/demos/music/assets
    3rdparty/lvgl/demos/stress
    3rdparty/lvgl/demos/widgets
    3rdparty/lvgl/src
    3rdparty/lvgl/src/core
    3rdparty/lvgl/src/draw
    3rdparty/lvgl/src/draw/arm2d
    3rdparty/lvgl/src/draw/nxp
    3rdparty/lvgl/src/draw/nxp/pxp
    3rdparty/lvgl/src/draw/nxp/vglite
    3rdparty/lvgl/src/draw/sdl
    3rdparty/lvgl/src/draw/stm32_dma2d
    3rdparty/lvgl/src/draw/sw
    3rdparty/lvgl/src/draw/swm341_dma2d
    3rdparty/lvgl/src/extra
    3rdparty/lvgl/src/extra/layouts
    3rdparty/lvgl/src/extra/layouts/flex
    3rdparty/lvgl/src/extra/layouts/grid
    3rdparty/lvgl/src/extra/libs
    3rdparty/lvgl/src/extra/libs/bmp
    3rdparty/lvgl/src/extra/libs/ffmpeg
    3rdparty/lvgl/src/extra/libs/freetype
    3rdparty/lvgl/src/extra/libs/fsdrv
    3rdparty/lvgl/src/extra/libs/gif
    3rdparty/lvgl/src/extra/libs/png
    3rdparty/lvgl/src/extra/libs/qrcode
    3rdparty/lvgl/src/extra/libs/rlottie
    3rdparty/lvgl/src/extra/libs/sjpg
    3rdparty/lvgl/src/extra/others
    3rdparty/lvgl/src/extra/others/fragment
    3rdparty/lvgl/src/extra/others/gridnav
    3rdparty/lvgl/src/extra/others/ime
    3rdparty/lvgl/src/extra/others/imgfont
    3rdparty/lvgl/src/extra/others/monkey
    3rdparty/lvgl/src/extra/others/msg
    3rdparty/lvgl/src/extra/others/snapshot
    3rdparty/lvgl/src/extra/themes
    3rdparty/lvgl/src/extra/themes/basic
    3rdparty/lvgl/src/extra/themes/default
    3rdparty/lvgl/src/extra/themes/mono
    3rdparty/lvgl/src/extra/widgets
    3rdparty/lvgl/src/extra/widgets/animimg
    3rdparty/lvgl/src/extra/widgets/calendar
    3rdparty/lvgl/src/extra/widgets/chart
    3rdparty/lvgl/src/extra/widgets/colorwheel
    3rdparty/lvgl/src/extra/widgets/imgbtn
    3rdparty/lvgl/src/extra/widgets/keyboard
    3rdparty/lvgl/src/extra/widgets/led
    3rdparty/lvgl/src/extra/widgets/list
    3rdparty/lvgl/src/extra/widgets/menu
    3rdparty/lvgl/src/extra/widgets/meter
    3rdparty/lvgl/src/extra/widgets/msgbox
    3rdparty/lvgl/src/extra/widgets/span
    3rdparty/lvgl/src/extra/widgets/spinbox
    3rdparty/lvgl/src/extra/widgets/spinner
    3rdparty/lvgl/src/extra/widgets/tabview
    3rdparty/lvgl/src/extra/widgets/tileview
    3rdparty/lvgl/src/extra/widgets/win
    3rdparty/lvgl/src/font
    3rdparty/lvgl/src/hal
    3rdparty/lvgl/src/misc
    3rdparty/lvgl/src/widgets
    # ${LVGL_HEADERS}
    inc
    ui
    ui/components
)

file(GLOB_RECURSE SOURCES
    "3rdparty/lvgl/*.*"
    "inc/*.*"
    "src/*.*"
    "ui/*.*"
)

find_library(WIRINGPI_LIBRARY NAMES wiringPi)
find_package(Threads REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${WIRINGPI_LIBRARY})
target_link_libraries(${PROJECT_NAME} Threads::Threads)
