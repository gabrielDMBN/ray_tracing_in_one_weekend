#include "../rtweekend.h"
#include "../camera.h"
#include "../hittable.h"
#include "../hittable_list.h"
#include "../sphere.h"
#include "../material.h"

#include <fstream>
#include <iostream>

int main() {

    hittable_list world;

    auto red_metal    = make_shared<metal>(color(1.0, 0.0, 0.0), 0.0);
    auto green_metal  = make_shared<metal>(color(0.0, 1.0, 0.0), 0.0);
    auto blue_metal   = make_shared<metal>(color(0.0, 0.0, 1.0), 0.0);
    auto white_metal  = make_shared<metal>(color(1.0, 1.0, 1.0), 0.0);

    // 4 esferas nos vertces de um quadrado
    double radius = 0.5;
    double offset = 0.75;    //deslocamento do centro
    double z_pos  = -1.5;    // mesma profundidade

    //topo esquerda vermelh
    world.add(make_shared<sphere>(point3(-offset,  offset, z_pos), radius, red_metal));
    // topo direita verde
    world.add(make_shared<sphere>(point3( offset,  offset, z_pos), radius, green_metal));
    // baixo esquerda azul
    world.add(make_shared<sphere>(point3(-offset, -offset, z_pos), radius, blue_metal));

    // baix odireita  branca
    world.add(make_shared<sphere>(point3( offset, -offset, z_pos), radius, white_metal));

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width  = 400;
    cam.samples_per_pixel = 100;
    cam.max_depth         = 50;
    cam.vfov     = 70;
    cam.lookfrom = point3(0, 0, 1);         // posicao da camera
    cam.lookat   = point3(0, 0, z_pos);     // olhando no centro do "quadrado""
    cam.vup      = vec3(0, 1, 0);

    cam.render(world);
}
