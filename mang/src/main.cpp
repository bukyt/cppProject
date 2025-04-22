#include <cute.h>

using namespace Cute;
int main(int argc, char* argv[])
{
    // Create a window with a resolution of 640 x 480.
    CF_Result result = cf_make_app("Fancy Window Title", 0, 0, 0, 640, 480, CF_APP_OPTIONS_WINDOW_POS_CENTERED_BIT, argv[0]);
    if (is_error(result)) {
        printf("Error: %s\n", result.details);
        return -1;
    }

    while (cf_app_is_running())
    {
        cf_app_update(NULL);
        // All your game logic and updates go here...
        cf_app_draw_onto_screen(true);
    }

    cf_destroy_app();

    return 0;
}