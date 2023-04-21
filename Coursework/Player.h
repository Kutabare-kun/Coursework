#include <raylib.h>


class Player {
private:
    Rectangle playerRect;
    Vector2 velocity;
    float speed;

public:
    Player(float x, float y, float width, float height, float speed);

    void Update(float delta);

    void Draw();

    const Rectangle& GetPlayerRect() const { return playerRect; }
};