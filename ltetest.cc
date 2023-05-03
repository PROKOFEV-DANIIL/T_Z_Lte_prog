#include <ns3/core-module.h>
#include <ns3/network-module.h>
#include <ns3/mobility-module.h>
#include <ns3/lte-module.h>

using namespace ns3;

int
main(int argc, char *argv[])
{
    CommandLine cmd(__FILE__);
    cmd.Parse(argc, argv);
    
    //This will instantiate some common objects (e.g., the Channel object) and provide the methods to add eNBs and
    //UEs and configure them.
    Ptr<LteHelper> lteHelper = CreateObject<LteHelper>();
    
    //Setting Pf-Ff-Mac-Scheduler
    lteHelper->SetAttribute("Scheduler", StringValue("ns3::PfFfMacScheduler"));
    
    //Create Node objects for the eNB(s) and the UEs:
    NodeContainer enbNodes;
    enbNodes.Create(1);
    NodeContainer ueNodes;
    ueNodes.Create(2);
    
    //Configure the Mobility model for all the nodes:
    MobilityHelper mobility;
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(enbNodes);
    mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
    mobility.Install(ueNodes);
    
    //Install an LTE protocol stack on the eNB(s):
    NetDeviceContainer enbDevs;
    enbDevs = lteHelper->InstallEnbDevice(enbNodes);
    
    //Install an LTE protocol stack on the UEs:
    NetDeviceContainer ueDevs;
    ueDevs = lteHelper->InstallUeDevice(ueNodes);
    
    //Attach the UEs to an eNB. This will configure each UE according to the eNB configuration, and create an RRC
    //connection between them:
    lteHelper->Attach(ueDevs, enbDevs.Get(0));
    
    //Activate a data radio bearer between each UE and the eNB it is attached to:
    enum EpsBearer::Qci q = EpsBearer::GBR_CONV_VOICE;
    EpsBearer bearer(q);
    lteHelper->ActivateDataRadioBearer(ueDevs, bearer);
    
    //Set the stop time, because the start-of-subframe event is scheduled repeatedly,
    //and the ns-3 simulator scheduler will hence never run out of events:
    Simulator::Stop(Seconds(5));
    
    //Enabling the output to file of RLC, MAC level Key Performance Indicators
    lteHelper->EnableMacTraces();
    lteHelper->EnableRlcTraces();
    
    //Run the simulation:
    Simulator::Run();
    
    //Cleanup and exit:
    Simulator::Destroy();
    return 0;
}
