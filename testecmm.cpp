#include <fstream>
#include <iostream>


//TESTE DA GRADIENTE
int main() {
    //Tamanhos
    const int W = 256;
    const int H = 256;

    // Abre arquivo em modo texto
    std::ofstream out("image.ppm", std::ios::out);
    if (!out) {
        std::cerr << "Falha ao abrir image.ppm para escrita\n";
        return 1;
    }

    // Cabeçalho
    out << "P3\n" << W << ' ' << H << "\n255\n";

    // Pixels (gradiente simples nese caso)
    for (int j = 0; j < H; ++j) {
        for (int i = 0; i < W; ++i) {
            double r = double(i) / (W - 1);
            double g = 0.0;
            double b = double(j) / (H - 1);

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    //Fecha o arquivo
    out.close();
    std::cout << "Gerado: image.ppm (" << W << "x" << H << ")\n";
    return 0;
}
