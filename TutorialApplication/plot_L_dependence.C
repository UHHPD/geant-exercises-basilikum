#include "TFitResult.h"
#include <fstream>
#include <iostream>

void plot_L_dependence(){
    const int N = 7;
    double L_list[N] = {0};
    double sigma_list[N] = {0};

    ifstream fin("L_dependence");

    for(int i=0; i<N; i++){
        double L;
        double sigma;
        fin >> L;
        fin >> sigma;
        L_list[i] = L;
        sigma_list[i] = sigma;
    }

    TCanvas* c1 = new TCanvas("c1");
    auto g = new TGraph(N, L_list, sigma_list);
//    g->SetTitle("L dependence of momentum resolution;L (cm);#sigma [MeV]")
    g->SetTitle("L dependence of momentum resolution;L [cm];#sigma [GeV/c]");

    TF1 *f1 = new TF1("f1", "[0]/x/x + [1]", 10, 100);
    //f1->SetParNames("Constant", 1);

    TFitResultPtr res = g->Fit("f1", "S"); // a "smart pointer", that properly releases the memory allocated by the hpt->Fit resu$
    std::cout << "sigma = " << res->Parameter(0) << std::endl;

    g->Draw("AP*");
}

