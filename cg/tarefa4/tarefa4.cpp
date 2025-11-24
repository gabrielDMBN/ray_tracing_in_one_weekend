
#include "../color.h"
#include "../vec3.h"

#include <fstream>
#include <iostream>

int main() {
    const int image_width  = 256;
    const int image_height = 256;

    // Abre arquivo PPM em modo texto (P3)
    std::ofstream out("image.ppm", std::ios::out);
    if (!out) {
        std::cerr << "Falha ao abrir image.ppm para escrita\n";
        return 1;
    }

    // Cabeçalho PPM
    out << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Render (gradiente)
    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines restantes: " << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {
            double u = double(i) / (image_width  - 1);   // 0..1 eixo X
            double v = double(j) / (image_height - 1);   // 0..1 eixo Y

            color pixel_color(u, v, 0.0);                // usa vec3 como cor
            write_color(out, pixel_color);               // escreve no arquivo
        }
    }

    out.close();
    std::clog << "\nDone.\n";
    return 0;
}
