#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include <TH1.h> 
#include <TH2.h> 
#include <TCanvas.h> 
#include <TLatex.h>
#include <TSystem.h>

void tempPerDay(TString ymd, TString hms, const char* town){

string fileName = Form("../CleansedData/Cleansed%sData.txt", town);

ifstream tempo(fileName);

tempo.close();
ifstream file(fileName);

TH1D* hist = new TH1D("Stats", Form("Temp. per day in %s at %d:00 UTC in %d; Day; Temperature [#circC]",town,ymd,hms), 
			366, 0, 366);

TString ymd, hms;
//Int_t month;
//Int_t day;
//Int_t time;
Double_t temp;

while (file >> ymd >> hms >> temp ){
	
	TDatime t(ymd + " " + hms); // "yyyy-mm-dd hh:mm:ss"
	g->SetPoint(g->GetN(), t.Convert(), v);

	if (Year == year && time == hour) {
	
	hist->SetBinContent(dayno,temp); 
	}

	else {
	
	continue;
	} 
} 

file.close();

TCanvas* can = new TCanvas("can", "hist canvas", 900, 600);
hist->SetLineColor(1);
hist->Draw();

can->SaveAs("hist.png");

}
