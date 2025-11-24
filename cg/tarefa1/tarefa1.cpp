#include <fstream>
#include <iostream>


//XADREZ !
int main() {
    //Tamanhos
    const int W = 256;
    const int H = 256;

    //XADREZ 8x8
    int boardSize = 8;
    int blockSize = W / boardSize;

    // Abre arquivo em modo texto
    std::ofstream out("image.ppm", std::ios::out);
    if (!out) {
        std::cerr << "Falha ao abrir image.ppm para escrita\n";
        return 1;
    }

    // Cabeçalho
    out << "P3\n" << W << ' ' << H << "\n255\n";

    // Pixels
    for (int j = 0; j < H; ++j) {
        for (int i = 0; i < W; ++i) {
            int block_x = i/blockSize;
            int block_y = j/blockSize;

            int ir ,ig , ib;

            if ((block_x + block_y) %2 != 0)
                ir = ig = ib = 255;
            else
                ir= ig= ib = 0;

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    //Fecha o arquivo
    out.close();
    std::cout << "Gerado: image.ppm (" << W << "x" << H << ")\n";
    return 0;
}
