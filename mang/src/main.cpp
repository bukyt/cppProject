#include <cute.h>
using namespace Cute;

void mount_content_directory_as(const char* dir)
{
    CF_Path path = fs_get_base_directory();
    path.normalize();
    path.pop(2); // Pop out of build/debug/
    path += "/content";
    fs_mount(path.c_str(), dir);
}

int main(int argc, char* argv[])
{
    mount_content_directory_as(".");
    CF_Result result = make_app("Basic Sprite", 0, 0, 0, 640, 480, CF_APP_OPTIONS_WINDOW_POS_CENTERED_BIT, argv[0]);
    if (is_error(result)) return -1;

    CF_Sprite girl_sprite = cf_make_demo_sprite();
    girl_sprite.animation = girl_sprite.animations[0];
    girl_sprite.scale = V2(4, 4);
    cf_sprite_play(&girl_sprite, "idle");
    while (app_is_running()) {
        app_update();
        cf_sprite_update(&girl_sprite);
        cf_draw_sprite(&girl_sprite);
        app_draw_onto_screen();
    }

    destroy_app();

    return 0;
}