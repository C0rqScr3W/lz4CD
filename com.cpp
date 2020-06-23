#include <iostream>
#include <vector>
#include <lz4.h>

using namespace std;

using buffer = vector<char>;

void lz4_compress(const buffer& in, buffer& out)
{
    auto rv = LZ4_compress_default(indata(), out.data(), in.size(), out.size());
    if(rv < 1) cerr << "Something Went Wrong Friend!" << endl;
    else out.resize(rv);
}

void lz4_decompress(const buffer& in, buffer& out)
{
    auto rv = LZ4_decompress_safe(in.data(), out.data(), in.size(), out.size());
    if(rv < 1) cerr << "Something is Wrong!" << endl;
    else out.resize(rv);
}

int main(int argc, char** argv)
{
    buffer data(1000, 'X');
    buffer compressed(data.size()), decompressed(data.size());

    lz4_compress(data, compressed);
    cout << "LZ$ decompress, bytes in: " << compressed.size() << ", bytes out: " << decompressed.size() << endl;

    if(data != decompressed) cerr << "Data Mismatch!" << endl;
    else cout << "Decompressed data matches Original" << endl;

    return 1;
}