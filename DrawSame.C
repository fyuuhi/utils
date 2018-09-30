#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TString.h>


void DrawSame(){
  TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00359918.physics_Main.YFTAP.f969_m2020_RateJPZtapv5_EXT0/merged.root");
  TString labelPDF = "merged.pdf";
  TCanvas *c1 = new TCanvas("c1", "c1", 10, 10, 1020, 700);
  c1->SetGrid();
  c1->SetRightMargin(0.20);
  c1->SetLeftMargin(0.23);
  c1->SetBottomMargin(0.20);

  //gStyle->SetPadTopMargin(0.06);
  gStyle->SetLegendBorderSize(0);

  c1 -> Print(labelPDF + "[", "pdf");
  c1 -> Print(labelPDF, "pdf");

  const int nMax = 4;
  Color_t histColor[nMax]        = {10, kYellow-3, kBlue, kRed};
  bool isFirstEvent = true;
  TString eachTrig[nMax] = {"L1", "SA", "Off", "OffPtCut"};

  typedef std::pair<TString, TString> pair;
  std::vector< pair > trigChain;
  trigChain.push_back( pair("HLT_noalg_L1MU4", "HLT_mu4") );
  trigChain.push_back( pair("HLT_mu4", "HLT_mu4") );
  trigChain.push_back( pair("HLT_noalg_L1MU6", "HLT_mu6") );
  trigChain.push_back( pair("HLT_noalg_L1MU20", "HLT_mu26_ivarmedium") );
  trigChain.push_back( pair("HLT_mu50", "HLT_mu50") );
  trigChain.push_back( pair("HLT_noalg_L1MU4", "HLT_noalg_L1MU4") );

  // chain loop
  for ( auto iChain: trigChain){
    // each trigger stage loop
    // Legend
    TLegend leg = TLegend(0.25,0.6,0.5,0.93);
    leg.SetTextSize(0.030);
    leg.SetFillStyle(0);
    leg.SetHeader(Form("#splitline{Collected by %s}{HLT Trigger: %s}", (iChain.first).Data(), (iChain.second).Data()),"");
    for ( int i = 0; i < nMax; i++){
      TH1F* tmp = (TH1F*)file1->Get("count" + eachTrig[i] + "_" + iChain.first + "_" + iChain.second);
      double yMax;
      if ( i == 0 ) {
        yMax = tmp->GetBinContent(tmp->GetMaximumBin()); 
        tmp -> GetYaxis() -> SetRangeUser( 0, yMax*1.7);
      }
      tmp->SetFillColor(histColor[i]);
      if ( i == 0 ) leg.AddEntry(tmp,"L1 outpus","f");
      if ( i == 1 ) leg.AddEntry(tmp,"SA outpus","f");
      if ( i == 2 ) leg.AddEntry(tmp,Form("offline muons (p_T > 4 GeV && %s", iChain.second.Data()),"f");
      if ( i == 3 ) leg.AddEntry(tmp,"pt","f");
      if (isFirstEvent) {
        tmp->Draw();
        isFirstEvent = false;;
      }
      if (!isFirstEvent) tmp->Draw("same");
    }
    // for next chain
    isFirstEvent = true;

    leg.Draw();
    c1 -> Print(labelPDF, "pdf");
  }

  c1 -> Print(labelPDF + "]", "pdf");
}
