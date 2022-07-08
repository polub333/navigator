#ifndef ENGINE_H
#define ENGINE_H

#include <Scene/scene.h>

class Engine
{
public:
    Engine();
    void setScene(Scene* _scene);
private:
    Scene* scene;
};

#endif // ENGINE_H
