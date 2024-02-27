# ifndef LELVEL_ONE_HPP
# define LELVEL_ONE_HPP


# include <raylib.h>
# include "game.hpp"
# include "scene.hpp"


struct Score {
    const char *text;
    float points {0};
    float points_in {0};
    Color color {BLACK};
    int font_size {40};
    int x {0};
    int y {0};
};


struct Circle {
    int radius;
    Color color {LIGHTGRAY};
    Vector2 center;
};


struct Rect {
    Image image;
    Texture2D texture;
    Color color {WHITE};
    Color tint {WHITE};
    int x;
    int y;
};


class LevelOne : public Scene
{
private:
    Color pixel_color {BLUE};
    Score score;
    Circle circle;
    Rect rect;

public:
    LevelOne(Game *game);
    ~LevelOne();
    void check_events() override;
    void update() override;
    void draw() override;
};


# endif
