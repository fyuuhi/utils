#include <TFile.h>
#include <TH1.h>
#include <TExec.h>
#include <TCanvas.h>
#include <TString.h>
#include <TLegend.h>
#include <TEfficiency.h>
using namespace std;

void drawtext(TGraph g, TLatex l, Color_t color, double size);

void Draw0624(){
  //TFile *file1 = new TFile("/gpfs/fs7001/yfukuhar/workspace/TestCalcEffTool/CalcEffTool/run/FtkExtrapolate_21_5_bsub_20_1.root");
  TFile *file1 = new TFile("/gpfs/fs7001/yfukuhar/workspace/TestCalcEffTool/CalcEffTool/run/FTK_424103_fix.root");
  //TFile *file2 = new TFile("/gpfs/fs7001/yfukuhar/workspace/TestCalcEffTool/CalcEffTool/run/FtkExtrapolate_21_5_bsub_20_tree.root");
  TFile *file2 = new TFile("/gpfs/fs7001/yfukuhar/workspace/TestCalcEffTool/CalcEffTool/run/mc16e_Jpsimu4mu4_0627.root");
  //TFile *file2 = new TFile("/gpfs/fs7001/yfukuhar/workspace/TestCalcEffTool/CalcEffTool/run/Output/_home_yfukuhar_gpfs_data_mc16_FTK_mc16_13TeV.424100.Pythia8B_A14_CTEQ6L1_Jpsimu4mu4.merge.AOD.e3735_s3126_d1480_d1471_r10681_r10682_AOD.15260609._000001.pool.root.1/test0605_01.root");
  //TFile *file1 = new TFile("/gpfs/home/yfukuhar/work/TestCalcEffTool/CalcEffTool/run/Output/_gpfs_fs6001_yfukuhar_data_data18_rate_data18_13TeV_data18_13TeV.00359918.physics_Main.merge.AOD.f969_m2020._lb0530._0003.1/test0605_01.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00358615.physics_Main.YFTAP.f961_m2020_RateJPZtapv6_EXT0/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00358577.physics_Main.YFTAP.f961_m2015_RateJPZtapv6_EXT0/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00358541.physics_Main.YFTAP.f961_m2015_RateJPZtapv6_EXT0/merged.root");
  //TFile *file1 = new TFile("/gpfs/fs2001/yfukuhar/data/data18_rate/user.yfukuhar.00359918.physics_Main.YFTAP.f969_m2020_RateJPZtapv6_EXT0/merged.root");
  TString labelPDF = "test1.pdf";
  //TString labelPDF = "merged.pdf";
  TCanvas *c1 = new TCanvas("c1", "c1", 10, 10, 1020, 700);
  c1->SetGrid();
  c1->SetRightMargin(0.20);
  c1->SetLeftMargin(0.23);
  c1->SetBottomMargin(0.20);

  //gStyle->SetPadTopMargin(0.06);
  gStyle->SetLegendBorderSize(0);

  c1 -> Print(labelPDF + "[", "pdf");
  c1 -> Print(labelPDF, "pdf");

  //pT
  //inner
  TH1F* pt0 = (TH1F*)file1->Get("ptFtk_0");
  TH1F* pt1 = (TH1F*)file1->Get("ptFtk_1");

  pt0->Draw();
  pt1->SetLineColor(kRed);
  pt1->Draw("same");
  c1 -> Print(labelPDF, "pdf");

  TEfficiency *heff_pt01;
  if (TEfficiency::CheckConsistency(*pt1, *pt0, "w")){
    heff_pt01 = new TEfficiency(*pt1, *pt0);
    heff_pt01->SetTitle("Fraction of female;pT[GeV];Fraction");
  }
  heff_pt01->Draw();
  c1 -> Print(labelPDF, "pdf");

  //pT
  //middle
  TH1F* pt2 = (TH1F*)file1->Get("ptFtk_2");
  TH1F* pt3 = (TH1F*)file1->Get("ptFtk_3");

  pt2->Draw();
  pt3->SetLineColor(kRed);
  pt3->Draw("same");
  c1 -> Print(labelPDF, "pdf");

  TEfficiency *heff_pt23;
  if (TEfficiency::CheckConsistency(*pt3, *pt2, "w")){
    heff_pt23 = new TEfficiency(*pt3, *pt2);
    heff_pt23->SetTitle("Fraction of female;pT[GeV];Fraction");
  }
  heff_pt23->Draw();
  c1 -> Print(labelPDF, "pdf");

  //pT
  //outer
  TH1F* pt3 = (TH1F*)file1->Get("ptFtk_3");
  TH1F* pt5 = (TH1F*)file1->Get("ptFtk_4");

  pt3->Draw();
  pt4->SetLineColor(kRed);
  pt4->Draw("same");
  c1 -> Print(labelPDF, "pdf");

  TEfficiency *heff_pt45;
  if (TEfficiency::CheckConsistency(*pt4, *pt3, "w")){
    heff_pt45 = new TEfficiency(*pt4, *pt3);
    heff_pt45->SetTitle("Fraction of female;pT[GeV];Fraction");
  }
  heff_pt45->Draw();
  c1 -> Print(labelPDF, "pdf");

  //extFlag
  TH1F* extFlag1 = (TH1F*)file1->Get("extFlag_0");
  TH1F* extFlag2 = (TH1F*)file1->Get("extFlag_1");

  extFlag1->Draw();
  extFlag2->SetLineColor(kRed);
  extFlag2->Draw("same");
  c1 -> Print(labelPDF, "pdf");

  TEfficiency *heff_extFlag;
  if (TEfficiency::CheckConsistency(*extFlag2, *extFlag1, "w")){
    heff_extFlag = new TEfficiency(*extFlag2, *extFlag1);
    heff_extFlag->SetTitle("Fraction of female;Flag;Fraction");
  }
  heff_extFlag->Draw();

  c1 -> Print(labelPDF, "pdf");

  c1 -> Print(labelPDF + "]", "pdf");

  TTree* tree=(TTree*)file2->Get("MyTree");

  int nMuons = 0;
  int nFtks = 0;
  int eventNumber;
  int runNumber;
  int lumiBlock;
  float averageInteractionsPerCrossing;
  std::vector<int> *muon_author=0;
  std::vector<int> *muon_type=0;
  std::vector<double> *muon_phi=0;
  std::vector<double> *muon_eta=0;
  std::vector<double> *muon_pt=0;
  std::vector<double> *ftk_pt=0;
  std::vector<double> *ftk_eta=0;
  std::vector<double> *ftk_phi=0;
  tree->SetBranchAddress("nMuons",      &nMuons);
  tree->SetBranchAddress("nFtks",       &nFtks);
  tree->SetBranchAddress("muon_author", &muon_author);
  tree->SetBranchAddress("muon_type",   &muon_type);
  tree->SetBranchAddress("muon_phi",    &muon_phi);
  tree->SetBranchAddress("muon_eta",    &muon_eta);
  tree->SetBranchAddress("muon_pt",     &muon_pt);
  tree->SetBranchAddress("ftk_phi",     &ftk_phi);
  tree->SetBranchAddress("ftk_eta",     &ftk_eta);
  tree->SetBranchAddress("ftk_pt",      &ftk_pt);
  tree->SetBranchAddress("eventNumber", &eventNumber);
  tree->SetBranchAddress("runNumber", &runNumber);
  tree->SetBranchAddress("lumiBlock", &lumiBlock);
  tree->SetBranchAddress("averageInteractionsPerCrossing", &averageInteractionsPerCrossing);
  int nEntry = tree->GetEntries();
  cout << nEntry << endl;

  TCanvas *c2 = new TCanvas("c2", "c2", 10, 10, 1020, 700);
  TString pdf = "dp.pdf";
  c2->SetGrid();
  c2->SetRightMargin(0.20);
  c2->SetLeftMargin(0.23);
  c2->SetBottomMargin(0.20);
  c2->Print(pdf + "[", "pdf");

  c2->Print(pdf, "pdf");


  // for TTree
  int max = 500;
  //int max = nEntry;
  for(int iEntry=0;iEntry<max;++iEntry){
    tree->GetEntry(iEntry);

    if (nFtks < 20){
      continue;
    }

    TH1 *frame = c2->DrawFrame(-3.5,-3.5,3.5,3.5);
    frame->GetXaxis()->SetTitle("#eta");
    frame->GetYaxis()->SetTitle("#phi");

    cout << runNumber << endl;
    cout << eventNumber << endl;


    //muon
    TGraph grMuon = TGraph(nMuons);
    TLatex lMuon;
    Double_t xMuon,yMuon;
    lMuon.SetTextSize(0.003);
    lMuon.SetTextFont(42);
    lMuon.SetTextAlign(21);
    lMuon.SetTextColor(kRed);
    //TGraph *g = (TGraph*)gPad->GetListOfPrimitives()->FindObject("Graph");
    //n = g.GetN();
    //cout << "drawtext" << n << endl;
    //for (i=0; i<n; i++) {
    //  g.GetPoint(i,x,y);
    //  l->PaintText(x,y+0.2,Form("(%4.2f,%4.2f)",x,y));
    //}
    grMuon.Draw("p");
    for ( int i = 0; i < nMuons; i++){
      cout << "Muon(" << i << ") pt/eta/phi=" << muon_pt->at(i) << "/" << muon_eta->at(i) << "/" << muon_phi->at(i) << endl;
      //if (muon_type->at(i) != 1 ){
      //  continue;
      //}
      grMuon.SetPoint(i, muon_eta->at(i), muon_phi->at(i));
      grMuon.GetPoint(i,xMuon,yMuon);
      //lMuon.DrawText(xMuon,yMuon+0.05,Form("%i (%4.2f,%4.2f)",muon_type->at(i),xMuon,yMuon));
      lMuon.DrawText(xMuon,yMuon+0.05,Form("%4.2fGeV (%4.3f,%4.3f)",muon_pt->at(i)/1000.,xMuon,yMuon));
      //lMuon.DrawText(xMuon,yMuon+0.1,Form("(%4.2f,%4.2f)",xMuon,yMuon));
      //lMuon.DrawText(xMuon,yMuon+0.0,Form("(%4.2f)",muon_pt->at(i)/1000.));
    }
    grMuon.SetMarkerStyle(21);
    grMuon.SetMarkerSize(1);
    //grMuon.SetMarkerColor(kRed);
    grMuon.SetMarkerColorAlpha(kRed, 0.30);

    //TExec *exMuon = new TExec("exMuon","drawtext(grMuon);");
    //grMuon.GetListOfFunctions()->Add(exMuon);

    grMuon.Draw("p");

    //ftk
    cout << "nMuons/nFtks=" << nMuons << "/" << nFtks << endl;
    TGraph grFtk = TGraph(nFtks);

    TLatex lFtk;
    Double_t xFtk,yFtk;
    lFtk.SetTextSize(0.003);
    lFtk.SetTextFont(42);
    lFtk.SetTextAlign(21);
    lFtk.SetTextColor(kBlue-4);
    for ( int i = 0; i < nFtks; i++){
      cout << "FTK(" << i << ") pt/eta/phi=" << ftk_pt->at(i) << "/" << ftk_eta->at(i) << "/" << ftk_phi->at(i) << endl;
      grFtk.SetPoint(i, ftk_eta->at(i), ftk_phi->at(i));
      grFtk.GetPoint(i,xFtk,yFtk);
      lFtk.DrawText(xFtk,yFtk+0.03,Form("%4.2fGeV (%4.3f,%4.3f)",ftk_pt->at(i)/1000.,xFtk,yFtk));
      //lFtk.DrawText(xFtk,yFtk+0.05,Form("(%4.2f,%4.2f)",xFtk,yFtk));
      //lFtk.DrawText(xFtk,yFtk+0.0,Form("(%4.2f)",ftk_pt->at(i)/1000.));
    }
    grFtk.SetMarkerStyle(22);
    grFtk.SetMarkerSize(1);
    grFtk.SetMarkerColorAlpha(kCyan-3, 0.50);


    TLegend leg = TLegend(0.805,0.22,0.99,0.95);
    leg.SetTextSize(0.035);
    leg.AddEntry(&grMuon,Form("#splitline{Offline}{segment (%d)}",nMuons),"p");
    leg.AddEntry(&grFtk,Form("#splitline{FTK}{track} (%d)",nFtks),"p");
    leg.Draw();
    //TExec *exFtk = new TExec("exFtk","drawtext(grFtk);");
    //grFtk.GetListOfFunctions()->Add(exFtk);
    grFtk.Draw("p same");
    //drawtext(grFtk,lFtk, kBlue, 0.005);
    //drawtext(grMuon,lMuon, kRed, 0.005);

    TText eventInfo = TText(0.05,0.02,Form("EventNumber = %d, RunNumber = %d, LumiBlock = %d, AverageInteractionsPerCrossing = %5.3f",eventNumber, runNumber, lumiBlock, averageInteractionsPerCrossing));
    eventInfo.SetNDC();
    eventInfo.SetTextSize(0.03);
    eventInfo.Draw();

    c2->Print(pdf, "pdf");

    delete frame;
  }

  c2->Print(pdf + "]", "pdf");
}

void drawtext(TGraph g, TLatex l, Color_t color, double size)
{
  cout << "drawtext" << endl;
  Int_t i,n;
  Double_t x,y;
  l.SetTextSize(size);
  l.SetTextFont(42);
  l.SetTextAlign(21);
  l.SetTextColor(color);
  //TGraph *g = (TGraph*)gPad->GetListOfPrimitives()->FindObject("Graph");
  n = g.GetN();
  cout << "drawtext" << n << endl;
  for (i=0; i<n; i++) {
    g.GetPoint(i,x,y);
    l.DrawText(x,y+0.1,Form("(%4.2f,%4.2f)",x,y));
  }
}
