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
#include "TGraphErrors.h"

//use 256 colors.
void setup(){
  gROOT->SetStyle("Plain");
  gStyle -> SetNumberContours(100);
  const Int_t NRGBs = 5;
  Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
  Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
  Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
  Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
  TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, 256);
}

void SetMaingPad(){
  gStyle -> SetPadGridX(1);
  gStyle -> SetPadGridY(1);
  gStyle -> SetOptStat(0);
  gPad -> SetRightMargin(0.2);
  gPad -> SetLeftMargin(0.3);
  gPad -> SetTopMargin(0.03);
  gPad -> SetBottomMargin(0.15);
}

void SetRatiogPad(){
  gROOT -> SetStyle("Plain");
  gStyle -> SetPadGridX(1);
  gStyle -> SetPadGridY(1);
  gStyle -> SetOptStat(0);
  gPad -> SetRightMargin(0.2);
  gPad -> SetLeftMargin(0.3);
  gPad -> SetTopMargin(0.05);
  gPad -> SetBottomMargin(0.4);
}


void SetMainHist(TH1F* h_data, TH1F* h_mc, TString title){

  h_data -> SetTitle(title);
  h_data -> GetYaxis()->SetRangeUser(0.,1.1);
  h_data -> GetXaxis()->SetTitleSize(0);
  h_data -> GetXaxis()->SetLabelSize(0);
  h_data -> GetYaxis()->SetLabelSize(0.07);
  h_data -> GetYaxis() -> SetTitleOffset(0.5);
  h_data -> SetMarkerStyle(20);
  h_data -> SetMarkerSize(1.2);
  h_data -> SetMarkerColor(1);
  h_data -> SetLineColor(1);
  h_data -> Draw();

  h_mc -> SetTitle(title);
  h_mc -> GetYaxis()->SetRangeUser(0.,1.1);
  h_mc -> GetXaxis()->SetTitleSize(0);
  h_mc -> GetXaxis()->SetLabelSize(0);
  h_mc -> SetMarkerStyle(20);
  h_mc -> SetMarkerSize(1.2);
  h_mc -> SetMarkerColor(2);
  h_mc -> SetLineColor(2);
  h_mc -> Draw("SAME");
}


void SetRatioHist(TH1F* h_ratio){

  h_ratio -> SetTitle("");
  h_ratio -> GetXaxis() -> CenterTitle();
  h_ratio -> GetYaxis() -> CenterTitle();
  h_ratio -> GetXaxis() -> SetLabelSize(0.15);
  h_ratio -> GetYaxis() -> SetLabelSize(0.15);
  h_ratio -> GetXaxis() -> SetLabelOffset(0.03);
  h_ratio -> GetYaxis() -> SetLabelOffset(0.02);
  h_ratio -> GetXaxis() -> SetTitleSize(0.12);
  h_ratio -> GetYaxis() -> SetTitleSize(0.15);
  h_ratio -> GetXaxis() -> SetTitleOffset(1.30);
  h_ratio -> GetYaxis() -> SetTitleOffset(0.5);
  h_ratio -> GetXaxis() -> SetNdivisions(509);
  h_ratio -> GetYaxis() -> SetNdivisions(509);
  h_ratio -> SetMinimum(0);

  h_ratio -> GetYaxis()->SetRangeUser(0.7,1.3);
  h_ratio -> GetYaxis() -> SetNdivisions(505);
  h_ratio -> SetMarkerStyle(20);
  h_ratio -> SetMarkerSize(1.2);
  h_ratio -> SetMarkerColor(1);

  h_ratio -> Draw("P");

}

void RatioLoop(TH1F *h_data, TH1F* h_mc, TH1F* h_ratio, int nbinX){
  double entry[3], error[3];

  //For Lopp for ratio histgram
  for (int ibinX=0; ibinX<nbinX; ibinX++) {
    entry[0] = h_data->GetBinContent(ibinX+1);
    error[0] = h_data->GetBinError(ibinX+1);
    entry[1] = h_mc->GetBinContent(ibinX+1);
    error[1] = h_mc->GetBinError(ibinX+1);
    entry[2] = ( entry[1]!=0 )? entry[0]/entry[1]:0;
    error[2] = ( entry[1]!=0 )? sqrt( entry[0]*entry[0]*error[1]*error[1] + entry[1]*entry[1]*error[0]*error[0] )/( entry[1]*entry[1] ):0;

    h_ratio->SetBinContent(ibinX+1, entry[2]);
    h_ratio->SetBinError(ibinX+1, error[2]);
    //std::cout << ibinX << std::endl;
    //std::cout << "data :" << entry[0] << std::endl;
    //std::cout << "mc :" <<  entry[1] << std::endl;
    //std::cout << "ratio :" << entry[2] << std::endl;
  }

}

void SetLegend(TH1F* h_data, TH1F* h_mc){

  TLegend *la = new TLegend(0.6,0.2,0.74,0.4,"");
  la -> AddEntry(h_data,"349533","lep");
  la -> AddEntry(h_mc,"349014","lep");
  la -> Draw();

}


void MainProcess(TCanvas* can, TH1F* h_data, TH1F* h_mc, TString h_title, TString pdf_name ){

  //divide canvas
  TPad* pa1 = new TPad("main","main",0.0,0.2,1.0,1.0,10,0,0);
  pa1->Draw();
  pa1->SetNumber(1);
  TPad* pa2 = new TPad("ratio","ratio",0.0,0.0,1.0,0.3,10,0,0);
  pa2->SetBottomMargin(0.4);
  pa2->Draw();
  pa2->SetNumber(2);

  TString h_name;
  h_name.Form(h_title);

  int nbinX = h_data->GetXaxis()->GetNbins();
  //cout << "nbinX" <<  nbinX << endl;
  double *binX;
  binX = new double[nbinX+1];
  //For Lopp for ratio histgram
  for ( int ibinX = 0; ibinX < nbinX+1; ibinX++ ) {
    if(ibinX != nbinX+1){
      binX[ibinX] = h_data->GetBinLowEdge(ibinX+1);
    } else {
      binX[ibinX] = h_data->GetBinWidth(ibinX)+GetBinLowEdge(ibinX);
    }
  }

  TString titleX = h_data->GetXaxis()->GetTitle();
  TH1F* h_ratio  = new TH1F("h_ratio","title", nbinX, binX);
  h_ratio -> SetTitle("ratio");
  h_ratio -> GetXaxis() -> SetTitle(titleX);
  h_ratio -> GetYaxis() -> SetTitle("349533/349014");

  //main canvas
  can->cd(1);
  SetMaingPad();
  gStyle -> SetPadGridX(1);
  gStyle -> SetPadGridY(1);

  ///main histgrams
  SetMainHist(h_data, h_mc, h_title);

  //Draw legend
  SetLegend(h_data, h_mc);

  //ratio canvas
  can->cd(2);
  SetRatiogPad();

  //Loop for fill h_ratio
  RatioLoop(h_data, h_mc, h_ratio, nbinX);

  SetRatioHist(h_ratio);


  can -> Print(pdf_name, "pdf");

  std::cout << "+++++++++++++++++++" << std::endl;
  h_ratio -> Delete();
  delete[] binX;
  //h_ratio->Delete();

}
