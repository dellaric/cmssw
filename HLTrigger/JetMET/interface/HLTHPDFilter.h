#ifndef HLTrigger_JetMET_HLTHPDFilter_h
#define HLTrigger_JetMET_HLTHPDFilter_h

/** \class HLTHPDFilter
 *
 *  \author Fedor Ratnikov (UMd)
 *
 */

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/stream/EDFilter.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"

namespace edm {
  class ConfigurationDescriptions;
}

class HLTHPDFilter : public edm::stream::EDFilter<> {
public:
  explicit HLTHPDFilter(const edm::ParameterSet&);
  ~HLTHPDFilter() override;
  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
  bool filter(edm::Event&, const edm::EventSetup&) override;

private:
  edm::EDGetTokenT<HBHERecHitCollection> m_theRecHitCollectionToken;
  edm::InputTag mInputTag;  // input tag for HCAL HBHE digis
  double mEnergyThreshold;
  double mHPDSpikeEnergyThreshold;
  double mHPDSpikeIsolationEnergyThreshold;
  double mRBXSpikeEnergyThreshold;
  double mRBXSpikeUnbalanceThreshold;
};

#endif
