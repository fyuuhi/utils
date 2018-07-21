#include "TH1F.h"
#include "TF1.h"
#include "TH2F.h"
#include "TROOT.h"
#include "TFile.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TMath.h"
#include "TEfficiency.h"
#include "TString.h"
#include "TColor.h"
#include "TLegend.h"
#include "TGraphErrors.h"
#include "TApplication.h"
#include "TPaveText.h"
#include "TText.h"
#include "TLatex.h"
#include <vector>
#include <iostream>

using namespace std;

void Slice(TFile* file_1, TFile* file_2);


const double low_qeta = -1.2;
const double high_qeta = -1.0;

void EachBinDraw(){

  TFile * file_1;
  TFile * file_2;
  file_1     = new TFile("/gpfs/home/yfukuhar/gpfs/tmp/CalcEffPlotMakerOrigin/outroot/data/mc16c_Jpsimu6_mu10_all.root");
  //file_2     = new TFile("/gpfs/home/yfukuhar/gpfs/tmp/CalcEffPlotMakerOrigin/outroot/data/mc16c_Jpsimu6_NoTag_all_v2.root");
  //file_2     = new TFile("/gpfs/home/yfukuhar/gpfs/CalcEffPlotMakerOrigin/outroot/data/data16_yf_Jpsi_all.root");
  //file_2 = new TFile("/gpfs/home/yfukuhar/gpfs/CalcEffPlotMakerOrigin/outroot/data/data17_yf_Jpsi_all.root");
  file_2 = new TFile("/gpfs/home/yfukuhar/gpfs/CalcEffPlotMakerOrigin/outroot/data/jpsi_mc15_all_mod.root");
  Slice(file_1, file_2);
}

void Slice(TFile* file_1, TFile* file_2){
  //L1
  TH2F* h_probe_qetapt_mu4_L1_1      = (TH2F*)file_1 -> Get("h_probe_qetapt_mu4_L1");
  TH2F* h_probe_qetapt_mu4_L1_2      = (TH2F*)file_2 -> Get("h_probe_qetapt_mu4_L1");
  //SA
  TH2F* h_probe_qetapt_mu4_SA_1      = (TH2F*)file_1 -> Get("h_probe_qetapt_mu4_SA");
  TH2F* h_probe_qetapt_mu4_SA_2      = (TH2F*)file_2 -> Get("h_probe_qetapt_mu4_SA");

  int first_bin = h_probe_qetapt_mu4_L1_1->GetXaxis()->FindBin(low_qeta);
  int last_bin  = h_probe_qetapt_mu4_L1_1->GetXaxis()->FindBin(high_qeta);

  TH1D* sliced_L1_1 = h_probe_qetapt_mu4_L1_1 -> ProjectionY("name_L1_1", first_bin, last_bin);
  TH1D* sliced_SA_1 = h_probe_qetapt_mu4_SA_1 -> ProjectionY("name_SA_1", first_bin, last_bin);

  TH1D* sliced_L1_2 = h_probe_qetapt_mu4_L1_2 -> ProjectionY("name_L1_2", first_bin, last_bin);
  TH1D* sliced_SA_2 = h_probe_qetapt_mu4_SA_2 -> ProjectionY("name_SA_2", first_bin, last_bin);


  sliced_SA_1 -> Divide(sliced_L1_1);
  sliced_SA_1 -> GetYaxis() -> SetRangeUser(0.,1.1);
  sliced_SA_1 -> Draw("p");

  sliced_SA_2 -> Divide(sliced_L1_2);
  sliced_SA_2 -> SetMarkerColor(2);
  sliced_SA_2 -> Draw("p same");

  //TEfficiency *heff_1 = new TEfficiency("heff_1", "heff_1",sliced_SA_1, sliced_L1_1);
  //TEfficiency *heff_2 = new TEfficiency("heff_2", "heff_2",sliced_SA_2, sliced_L1_2);

  //heff_1 -> GetYaxis() -> SetRangeUser(0.,1.1);
  //heff_1 -> Draw("");

  //heff_2 -> SetMarkerColor(2);
  //heff_2 -> Draw("same");
}


//void EachBinDraw(TH2F* h_probe_qetapt_mu4_L1, TH2F* h_probe_qetapt_mu4_SA){
//  const double low_qeta = -2.0;
//  const double high_qeta = -1.1;
//  int first_bin_L1 = h_probe_qetapt_mu4_L1->GetXaxis()->FindBin(low_qeta);
//  int last_bin_L1  = h_probe_qetapt_mu4_L1->GetXaxis()->FindBin(high_qeta);
//
//  int first_bin_SA = h_probe_qetapt_mu4_SA->GetXaxis()->FindBin(low_qeta);
//  int last_bin_SA  = h_probe_qetapt_mu4_SA->GetXaxis()->FindBin(high_qeta);
//
//  TH1D* sliced_L1 = h_probe_qetapt_mu4_L1 -> ProjectionY("name_L1", first_bin_L1, last_bin_L1);
//  TH1D* sliced_SA = h_probe_qetapt_mu4_SA -> ProjectionY("name_SA", first_bin_SA, last_bin_SA);
//
//  sliced_L1 -> Draw();
//  sliced_SA -> Draw("same");
//
//  //TH1F* L1SA -> Divide(sliced_L1, sliced_SA);
//  sliced_SA -> Divide(sliced_L1);
//  sliced_SA -> Draw("p");
//
//}



//void EachBinDraw(){
//  Int_t first_bin = h_eff_qetapt->GetXaxis()->FindBin(-1.3);
//  Int_t last_bin = h_eff_qetapt->GetXaxis()->FindBin(-1.05);
//  TH1D* eff_pt = h_eff_qetapt -> ProjectionY("name", first_bin, last_bin);
//  eff_pt -> Draw();
//
//}
//
