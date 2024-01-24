#include "TFitResult.h"
#include <fstream>
#include <iostream>

void plot_B_dependence(){
    const int N = 6;
    double B_list[N] = {0};
    double sigma_list[N] = {0};

    ifstream fin("B_dependence");

    for(int i=0; i<N; i++){
        double B;
        double sigma;
        fin >> B;
        fin >> sigma;
        B_list[i] = B;
        sigma_list[i] = sigma;
    }

    TCanvas* c1 = new TCanvas("c1");
    auto g = new TGraph(N, B_list, sigma_list);
    g->SetTitle("B dependence of momentum resolution;B [T];#sigma [GeV/c]");

    TF1 *f1 = new TF1("f1", "[0]/x + [1]", 0.5, 7);

    TFitResultPtr res = g->Fit("f1", "S"); // a "smart pointer", that properly releases the memory allocated by the hpt->Fit resu$
    std::cout << "sigma = " << res->Parameter(0) << std::endl;

    g->Draw("AP*");
}
