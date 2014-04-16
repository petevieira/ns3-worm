// GENERAL PUBLIC LICENSE AGREEMENT
// 
// PLEASE READ THIS DOCUMENT CAREFULLY BEFORE UTILIZING THE PROGRAM
// 
// BY UTILIZING THIS PROGRAM, YOU AGREE TO BECOME BOUND BY THE TERMS OF
// THIS LICENSE.  IF YOU DO NOT AGREE TO THE TERMS OF THIS LICENSE, DO
// NOT USE THIS PROGRAM OR ANY PORTION THEREOF IN ANY FORM OR MANNER.
// 
// This Program is licensed, not sold to you by GEORGIA TECH RESEARCH
// CORPORATION ("GTRC"), owner of all code and accompanying documentation
// (hereinafter "Program"), for use only under the terms of this License,
// and GTRC reserves any rights not expressly granted to you.
// 
// 1.  This License allows you to:
// 
// (a) make copies and distribute copies of the Program's source code
// provide that any such copy clearly displays any and all appropriate
// copyright notices and disclaimer of warranty as set forth in Article 5
// and 6 of this License.  All notices that refer to this License and to
// the absence of any warranty must be kept intact at all times.  A copy
// of this License must accompany any and all copies of the Program
// distributed to third parties.
// 
// A fee may be charged to cover the cost associated with the physical
// act of transferring a copy to a third party.  At no time shall the
// program be sold for commercial gain either alone or incorporated with
// other program(s) without entering into a separate agreement with GTRC.
//  
// 
// (b) modify the original copy or copies of the Program or any portion
// thereof ("Modification(s)").  Modifications may be copied and
// distributed under the terms and conditions as set forth above,
// provided the following conditions are met:
// 
//     i) any and all modified files must be affixed with prominent
// notices that you have changed the files and the date that the changes
// occurred.
// 		
//     ii) any work that you distribute, publish, or make available, that
// in whole or in part contains portions of the Program or derivative
// work thereof, must be licensed at no charge to all third parties under
// the terms of this License.
// 
//    iii) if the modified program normally reads commands interactively
// when run, you must cause it, when started running for such interactive
// use in the most ordinary way, to display and/or print an announcement
// with all appropriate copyright notices and disclaimer of warranty as
// set forth in Article 5 and 6 of this License to be clearly displayed.
// In addition, you must provide reasonable access to this License to the
// user.
// 
// Any portion of a Modification that can be reasonably considered
// independent of the Program and separate work in and of itself is not
// subject to the terms and conditions set forth in this License as long
// as it is not distributed with the Program or any portion thereof.
// 
// 
// 2. This License further allows you to copy and distribute the Program
//    or a work based on it, as set forth in Article 1 Section b in
//    object code or executable form under the terms of Article 1 above
//    provided that you also either:
// 
//    i) accompany it with complete corresponding machine-readable source
// code, which must be distributed under the terms of Article 1, on a
// medium customarily used for software interchange; or,
// 
//   ii) accompany it with a written offer, valid for no less than three
// (3) years from the time of distribution, to give any third party, for
// no consideration greater than the cost of physical transfer, a
// complete machine-readable copy of the corresponding source code, to be
// distributed under the terms of Article 1 on a medium customarily used
// for software interchange; or,
// 
// 
// 3.  Export Law Assurance.
// 
// You agree that the Software will not be shipped, transferred or
// exported, directly into any country prohibited by the United States
// Export Administration Act and the regulations thereunder nor will be
// used for any purpose prohibited by the Act.
//  
// 4.  Termination.
// 
// If at anytime you are unable to comply with any portion of this
// License you must immediately cease use of the Program and all
// distribution activities involving the Program or any portion thereof.
// 
// 
// 5.  Disclaimer of Warranties and Limitation on Liability.
// 
// YOU ACCEPT THE PROGRAM ON AN "AS IS" BASIS.  GTRC MAKES NO WARRANTY
// THAT ALL ERRORS CAN BE OR HAVE BEEN ELIMINATED FROM PROGRAM.  GTRC
// SHALL NOT BE RESPONSIBLE FOR LOSSES OF ANY KIND RESULTING FROM THE USE
// OF PROGRAM AND ITS ACCOMPANYING DOCUMENT(S), AND CAN IN NO WAY PROVIDE
// COMPENSATION FOR ANY LOSSES SUSTAINED, INCLUDING BUT NOT LIMITED TO
// ANY OBLIGATION, LIABILITY, RIGHT, CLAIM OR REMEDY FOR TORT, OR FOR ANY
// ACTUAL OR ALLEGED INFRINGEMENT OF PATENTS, COPYRIGHTS, TRADE SECRETS,
// OR SIMILAR RIGHTS OF THIRD PARTIES, NOR ANY BUSINESS EXPENSE, MACHINE
// DOWNTIME OR DAMAGES CAUSED TO YOU BY ANY DEFICIENCY, DEFECT OR ERROR
// IN PROGRAM OR MALFUNCTION THEREOF, NOR ANY INCIDENTAL OR CONSEQUENTIAL
// DAMAGES, HOWEVER CAUSED.  GTRC DISCLAIMS ALL WARRANTIES, BOTH EXPRESS
// AND IMPLIED RESPECTING THE USE AND OPERATION OF PROGRAM AND ITS
// ACCOMPANYING DOCUMENTATION, INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR PARTICULAR PURPOSE AND ANY IMPLIED
// WARRANTY ARISING FROM COURSE OF PERFORMANCE, COURSE OF DEALING OR
// USAGE OF TRADE.  GTRC MAKES NO WARRANTY THAT PROGRAM IS ADEQUATELY OR
// COMPLETELY DESCRIBED IN, OR BEHAVES IN ACCORDANCE WITH ANY
// ACCOMPANYING DOCUMENTATION.  THE USER OF PROGRAM IS EXPECTED TO MAKE
// THE FINAL EVALUATION OF PROGRAM'S USEFULNESS IN USER'S OWN
// ENVIRONMENT.
// 
// GTRC represents that, to the best of its knowledge, the software
// furnished hereunder does not infringe any copyright or patent.
// 
// GTRC shall have no obligation for support or maintenance of Program.
// 
// 6.  Copyright Notice.
// 
// THE SOFTWARE AND ACCOMPANYING DOCUMENTATION ARE COPYRIGHTED WITH ALL
// RIGHTS RESERVED BY GTRC.  UNDER UNITED STATES COPYRIGHT LAWS, THE
// SOFTWARE AND ITS ACCOMPANYING DOCUMENTATION MAY NOT BE COPIED EXCEPT
// AS GRANTED HEREIN.
// 
// You acknowledge that GTRC is the sole owner of Program, including all
// copyrights subsisting therein.  Any and all copies or partial copies
// of Program made by you shall bear the copyright notice set forth below
// and affixed to the original version or such other notice as GTRC shall
// designate.  Such notice shall also be affixed to all improvements or
// enhancements of Program made by you or portions thereof in such a
// manner and location as to give reasonable notice of GTRC's copyright
// as set forth in Article 1.
// 
// Said copyright notice shall read as follows:
// 
// Copyright 2004
// Dr. George F. Riley
// Georgia Tech Research Corporation
// Atlanta, Georgia 30332-0415
// All Rights Reserved
//
// $Id: wormudp.cc 391 2005-07-20 15:12:49Z mofta7 $



// Georgia Tech Network Simulator - UDP Worm class

// Monirul I Sharif,  Georgia Tech, Fall 2003

// Define a Worm Application class

// Uncomment below to enable debug level 0

//#define DEBUG_MASK 0x1

#include "debug.h"
#include "wormudp.h"
#include "udp.h"
#include "node.h"
#include "simulator.h"

#ifdef HAVE_QT
#include <qnamespace.h>
#endif

using namespace std;


Count_t  WormUDP::scanrate = 50;

// In this version of the worm application I am using a constant
//    packets per second method to sent UDP packets.
// I will later change this into a more robust method.

// Constructors


WormUDP::WormUDP()
  : udp(nil), timeoutevent(nil)
{

}

WormUDP::~WormUDP()
{
}

// Application Methods
void WormUDP::StartApp()    // Called at time specified by Start
{
  Worm::StartApp();
}

void WormUDP::StopApp()     // Called at time specified by Stop
{
  Worm::StopApp();
  if (timeoutevent) timer.Cancel(timeoutevent);
}

void WormUDP::AttachNode(Node* n) 
{
  Worm::AttachNode(n);

  udp = new UDP(n);
  
  udp->Attach(n);
  udp->Bind(infectionport);
  udp->AttachApplication(this);
  DEBUG0((cout << "udp " << udp << " , attach App " << this << endl));
}

Application* WormUDP::Copy() const
{
  return new WormUDP(*this);
}


void WormUDP::Activate()
{
  DEBUG0(( cout<<"Infected machine:"<< IPAddr::ToDotted(node->GetIPAddr())<<endl ));
  DEBUG0(( cout<<" Now starting timer event"<<endl));
  // Set the node to red on animation
#ifdef HAVE_QT
  node->Color(Qt::red);
#endif
  patchtime += Simulator::Now();


  if(!delayinitprobe)
    {
      SendWorm();
    }
  else
    {
      patchtime += (1.0 / (double)scanrate);
    }
  
  ScheduleNextPacket();
}


void WormUDP::Initialize()
{

}

void WormUDP::SendWorm()
{
  IPAddr_t target = GenerateNextIPAddress();  

  DEBUG0((cout<<"SendWorm["<<(string)IPAddr(node->GetIPAddr())<<
	  "]: Sending worm packet to "<<(string)IPAddr(target)<<endl));

  udp->SendTo(payloadlength, target, infectionport);
}

void WormUDP::SetScanRate(Count_t rate)
{
  scanrate = rate;
}

void WormUDP::Receive(Packet *p, L4Protocol *proto, Seq_t)
{
   DEBUG0((cout<<"Receive["<<(string)IPAddr(node->GetIPAddr())<<"]: Received TCP packet of size "<<p->Size()<<endl));
   
   if (PacketIsWorm(p)) {
     if (vulnerable && !infected) {
       Infect();
      }
   }
   delete p;
}

void WormUDP::ScheduleNextPacket()
{
  if(patchable)
    {
      if (Simulator::Now() >= patchtime)
	{
	  return;
	}
    }

  if (!timeoutevent) timeoutevent = new TimerEvent();
  timer.Schedule(timeoutevent, 1.0 / (double)scanrate, this);
}

void WormUDP::Timeout(TimerEvent *ev)
{
  if (!node)
    {
      cout << "WormUDP::Timeout with no attached node "<<endl;
      return;
    }

  DEBUG0((cout<< "WormUDPWorm::Timeout "<<Simulator::Now()<<endl));

  // Sending the worm packet
  SendWorm();
  ScheduleNextPacket();
}
