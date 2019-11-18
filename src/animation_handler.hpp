#ifndef ANIMATINO_HANDLER_HPP
#define ANIMATINO_HANDLER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
    unsigned int startFrame;
    unsigned int endFrame;

    float duration;

    Animation(unsigned int startFrame, unsigned int endFrame, float duration)
    {
        this->startFrame = startFrame;
        this->endFrame = endFrame;
        this->duration = duration;
    }

    unsigned int getLength() { return endFrame - startFrame + 1; }
};

class AnimationHandler
{
private:
    std::vector<Animation> animations;

    // current time since animation start
    float t;

    int currentAnimation;

public:
    void addAnimation(Animation &animiation);
    void update(const float dt);
    void changeAnimation(unsigned int animationNumber);

    // section of texture to display
    sf::IntRect bounds;
    // pixel dimension of frame
    sf::IntRect frameSize;

    AnimationHandler()
    {
        this->t = 0.0f;
        this->currentAnimation = -1;
    }

    AnimationHandler(const sf::IntRect &frameSize)
    {
        this->frameSize = frameSize;
        this->t = 0.0f;
        this->currentAnimation = -1;
    }
};

#endif