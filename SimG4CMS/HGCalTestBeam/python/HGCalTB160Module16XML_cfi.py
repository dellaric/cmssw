import FWCore.ParameterSet.Config as cms

XMLIdealGeometryESSource = cms.ESSource("XMLIdealGeometryESSource",
    geomXMLFiles = cms.vstring('Geometry/CMSCommonData/data/materials.xml',
        'Geometry/CMSCommonData/data/rotations.xml',
        'Geometry/HGCalCommonData/data/TB160/cms.xml',
        'Geometry/HGCalCommonData/data/TB160/hgcal.xml',
        'Geometry/HGCalCommonData/data/TB160/16Module/hgcalEE.xml',
        'Geometry/HGCalCommonData/data/hgcalwafer/v7/hgcalwafer.xml',
        'Geometry/HGCalCommonData/data/TB160/hgcalBeam.xml',
        'Geometry/HGCalCommonData/data/TB160/hgcalsense.xml',
        'Geometry/HGCalCommonData/data/TB160/hgcProdCuts.xml',
        'Geometry/HGCalCommonData/data/TB160/16Module/hgcalCons.xml',
        'SimG4CMS/HGCalTestBeam/data/CaloUtil.xml'),
    rootNodeName = cms.string('cms:OCMS')
)


