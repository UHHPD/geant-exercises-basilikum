#include <fstream>
#include <vector>

void plotMC(){
  const int N = 7;
//  std::vector<double> betagamma_list;
//  std::vector<double> mean_list; // vector push_back not working
  double betagamma_list[N] = {0};
  double mean_list[N] = {0};

  ifstream fin("MC_result");

  for(int i=0; i<N; i++){
    double betagamma;
    double mean;
    fin >> betagamma;
    fin >> mean;

//    betagamma_list.push_back(betagamma);
//    mean_list.pushback(mean);

    betagamma_list[i] = betagamma;
    mean_list[i] = mean;
}

  // plot


  TCanvas* c1 = new TCanvas("c1");
  c1->SetLogx();
  auto g = new TGraph(N, betagamma_list, mean_list);
  g->SetTitle("Cu 0.2 cm box;#beta#gamma;mean energy loss [MeV g^{-1} cm^{2}]");
  g->Draw("AC*");

}
