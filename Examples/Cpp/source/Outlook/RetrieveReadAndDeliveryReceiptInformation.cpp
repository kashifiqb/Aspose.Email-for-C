﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/date_time.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Formats/Outlook/Mapi/MapiRecipientCollection.h>
#include <Formats/Outlook/Mapi/MapiRecipient.h>
#include <Formats/Outlook/Mapi/MapiPropertyTag.h>
#include <Formats/Outlook/Mapi/MapiPropertyCollection.h>
#include <Formats/Outlook/Mapi/MapiProperty.h>
#include <Formats/Outlook/Mapi/MapiMessage.h>
#include <cstdint>

#include "Examples.h"


using namespace Aspose::Email;

using namespace Aspose::Email::Outlook;


void RetrieveReadAndDeliveryReceiptInformation()
{
    // The path to the File directory.
    System::String dataDir = GetDataDir_Outlook();
    
    // ExStart:RetrieveReadAndDeliveryReceiptInformation
    System::SharedPtr<MapiMessage> msg = MapiMessage::FromFile(dataDir + L"TestMessage.msg");
    
    {
        auto recipient_enumerator = (msg->get_Recipients())->GetEnumerator();
        decltype(recipient_enumerator->get_Current()) recipient;
        while (recipient_enumerator->MoveNext() && (recipient = recipient_enumerator->get_Current(), true))
        {
            System::Console::WriteLine(System::String::Format(L"Recipient: {0}",recipient->get_DisplayName()));
            
            // Get the PR_RECIPIENT_TRACKSTATUS_TIME_DELIVERY property
            System::Console::WriteLine(System::String::Format(L"Delivery time: {0}",recipient->get_Properties()->idx_get(MapiPropertyTag::PR_RECIPIENT_TRACKSTATUS_TIME_DELIVERY)->GetDateTime()));
            
            // Get the PR_RECIPIENT_TRACKSTATUS_TIME_READ property
            System::Console::WriteLine(System::String::Format(L"Read time: {0}",recipient->get_Properties()->idx_get(MapiPropertyTag::PR_RECIPIENT_TRACKSTATUS_TIME_READ)->GetDateTime()));
            
            System::Console::WriteLine();
        }
    }
    // ExEnd:RetrieveReadAndDeliveryReceiptInformation
}







