#include <game.h>
#include <grass_scene/grass_scene.h>

#include <glog/logging.h>

//------------------------------------------------------------------//

int main(int argc, char *argv[])
{
    (void)argc;
    google::InitGoogleLogging(argv[0]);

    Game g;
    GrassScene *grass_scene = new GrassScene();
    g.setScene(grass_scene);

    return g.run();
}

//------------------------------------------------------------------//
