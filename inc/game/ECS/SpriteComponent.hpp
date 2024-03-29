#ifndef SPRITECOMPONENTCLASS_HPP
#define SPRITECOMPONENTCLASS_HPP

#include "Components.hpp"
#include "../textureManager.hpp"
#include "Animation.hpp"
#include "SDL.h"
#include <map>

class SpriteComponent : public Component
{
private:
    PositionComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;

        bool animated = false;
        int frames = 0;
        int speed = 100;

public:
    int animIndex = 0;

    std::map<const char*, Animation> animations;

    SpriteComponent() = default;
    SpriteComponent(const char *path)
    {
        setTex(path);
    }

    SpriteComponent(const char *path, bool isAnimated)
    {
        animated = isAnimated;
        //Animation idle = Animation(0, 0, 100);
        Animation walk_front = Animation(0,ANIMATION_FPS, ANIMATION_SPEED);
        Animation walk_back = Animation(1,ANIMATION_FPS, ANIMATION_SPEED);
        Animation walk_left = Animation(2,ANIMATION_FPS, ANIMATION_SPEED);
        Animation walk_right = Animation(3,ANIMATION_FPS, ANIMATION_SPEED);

        animations.emplace("walk_front",walk_front);
        animations.emplace("walk_back",walk_back);
        animations.emplace("walk_left",walk_left);
        animations.emplace("walk_right",walk_right);

        play("walk_front");
        setTex(path);
    }

    ~SpriteComponent()
    {
        SDL_DestroyTexture(texture);
    }
    void init() override
    {
        transform = &entity->getComponent<PositionComponent>();

        srcRect.x = srcRect.y = 0;
        srcRect.w = 256; // To be changed when image sizes are standarized
        srcRect.h = 256; // To be changed when image sizes are standarized
    }
    void update() override
    {
        if (animated)
        {
            srcRect.x = srcRect.w * static_cast<int>(SDL_GetTicks() / speed % frames);
        }

        srcRect.y = animIndex * transform->height;

        destRect.x = transform->position.x - Game::camera.x;
        destRect.y = transform->position.y - Game::camera.y;
        destRect.w = static_cast<int>(transform->width * transform->scale);
        destRect.h = static_cast<int>(transform->height * transform->scale);
    }
    void draw() override
    {
        TextureManager::Draw(texture, srcRect, destRect);
    }

    void play(const char* animName)
    {
        frames = animations[animName].frames;
        animIndex = animations[animName].index;
        speed = animations[animName].speed;
    }

    void setTex(const char *path)
    {
        texture = TextureManager::LoadTexture(path);
    }
};

#endif