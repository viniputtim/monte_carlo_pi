# include "level_one.hpp"


LevelOne::LevelOne(Game *game) : Scene(game)
{
    int rect_size {(GetScreenWidth() > GetScreenHeight()) ? GetScreenHeight() : GetScreenWidth()};
    this->rect.image = GenImageColor(rect_size, rect_size, this->rect.color);
    this->rect.x = (GetScreenWidth() - rect_size) / 2;
    this->rect.y = (GetScreenHeight() - rect_size) / 2;

    this->circle.radius = rect_size / 2;
    this->circle.center.x = GetScreenWidth() / 2;
    this->circle.center.y = GetScreenHeight() / 2;

    ImageDrawCircle(
        &this->rect.image,
        this->circle.center.x - this->rect.x,
        this->circle.center.y - this->rect.y,
        this->circle.radius,
        this->circle.color
    );
}


LevelOne::~LevelOne()
{

}


void LevelOne::check_events()
{

}


void LevelOne::update()
{
    Vector2 point {
        static_cast<float> (GetRandomValue(this->rect.x, this->rect.x + this->rect.image.width)),
        static_cast<float> (GetRandomValue(this->rect.y, this->rect.y + this->rect.image.height))
    };

    ++this->score.points;

    if (CheckCollisionPointCircle(point, this->circle.center, this->circle.radius)) {
        ++this->score.points_in;
    }

    ImageDrawPixel(
        &this->rect.image,
        point.x - this->rect.x,
        point.y - this->rect.y,
        this->pixel_color
    );

    UnloadTexture(this->rect.texture);
    this->rect.texture = LoadTextureFromImage(this->rect.image);

    if (this->score.points != 0) {
        this->score.text = TextFormat("PI = %f", (this->score.points_in / this->score.points) * 4);
    }
}


void LevelOne::draw()
{
    ClearBackground(RAYWHITE);
    DrawTexture(this->rect.texture, this->rect.x, this->rect.y, this->rect.tint);
    DrawText(this->score.text, this->score.x, this->score.y, this->score.font_size, this->score.color);
}
