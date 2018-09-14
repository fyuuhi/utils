#include "TH1F.h"
#include "TH2F.h"
#include "TROOT.h"
#include "TFile.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TMath.h"
#include "TString.h"
#include "TColor.h"
#include "TLegend.h"
#include "TRatioPlot.h"
#include "TGraphErrors.h"
#include "rootlogon.C"

using namespace std;

void ratioPlot(TString name_file_bunshi, TString name_file_bunbo, TString name_hist_bunshi, TString name_hist_bunbo, TString name_pdf, TString name_legend_bunshi, TString name_legend_bunbo){


  rootlogon();
  gStyle->SetLegendBorderSize(0);

  TCanvas *c1 = new TCanvas("c1","c1",1000,720);
  c1->SetGrid();

  //Root File
  TFile *file_bunshi = new TFile(name_file_bunshi);
  TFile *file_bunbo  = new TFile(name_file_bunbo);

  //Histgrams
  TH1F *h_bunshi = (TH1F*)file_bunshi -> Get(name_hist_bunshi);
  TH1F *h_bunbo  = (TH1F*)file_bunbo  -> Get(name_hist_bunbo);

  auto h_ratio = new TRatioPlot(h_bunshi, h_bunbo);
  h_bunshi -> GetYaxis() -> SetTitle("Efficiency");
  TString titleX = h_bunshi -> GetXaxis() -> GetTitle();
  h_bunshi -> GetXaxis() -> SetTitle(titleX);
  //PDF_NAME
  TString pdf  = name_pdf;

  c1 -> Print(pdf + "[", "pdf");
 
  h_ratio -> Draw();
  //h_ratio -> SetH1DrawOpt("p");
  //h_ratio -> SetH2DrawOpt("p");
  c1 -> Print(pdf, "pdf");

  c1 -> Print(pdf + "]", "pdf");


  c1->Close();

  gROOT -> ProcessLine(".q");


}
