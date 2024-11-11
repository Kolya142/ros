#include <SFML/Graphics.h>

int main()
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window = sfRenderWindow_create(mode, "CSFML Test", sfClose, NULL);
    
    if (!window)
        return 1;

    while (sfRenderWindow_isOpen(window))
    {
        sfEvent event;
        while (sfRenderWindow_pollEvent(window, &event))
        {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfVector2i mouse = sfMouse_getPosition(window);
        sfVector2f mousef;
        mousef.x = (float)mouse.x-5;
        mousef.y = (float)mouse.y-5;
        sfRenderWindow_clear(window, sfBlack);
        sfCircleShape* circl = sfCircleShape_create();
        sfCircleShape_setRadius(circl, 10);
        sfCircleShape_setPosition(circl, mousef);
        sfRenderWindow_drawCircleShape(window, circl, NULL);
        sfRenderWindow_display(window);
    }

    sfRenderWindow_destroy(window);
    return 0;
}
