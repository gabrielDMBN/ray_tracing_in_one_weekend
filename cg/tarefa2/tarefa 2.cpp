#include <fstream>
#include "../vec3.h"


// Converte color (cada canal em [0,1]) para 0..255 e escreve no arquivo
inline void write_color(std::ofstream& out, const color& c) {
    auto r = c.x();
    auto g = c.y();
    auto b = c.z();

    // clamping simples para garantir faixa [0,1]
    if (r < 0) r = 0; if (r > 1) r = 1;
    if (g < 0) g = 0; if (g > 1) g = 1;
    if (b < 0) b = 0; if (b > 1) b = 1;

    int ir = static_cast<int>(255.999 * r);
    int ig = static_cast<int>(255.999 * g);
    int ib = static_cast<int>(255.999 * b);

    out << ir << ' ' << ig << ' ' << ib << '\n';
}

int main() {
    const int image_width  = 256;
    const int image_height = 256;

    std::ofstream out("image.ppm", std::ios::out);
    if (!out) { std::cerr << "Falha ao abrir image.ppm\n"; return 1; }

    // Cabeçalho PPM (P3 = texto)
    out << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Render: gradiente usando vec3 como "color"
    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            double u = double(i) / (image_width  - 1);  // 0..1 ao longo do eixo X
            double v = double(j) / (image_height - 1);  // 0..1 ao longo do eixo Y

            color pixel = color(u, v, 0.2);             // usa vec3 tanto pra cor quanto p/ ponto/dir
            write_color(out, pixel);
        }
    }

    out.close();

    return 0;
}
