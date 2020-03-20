﻿/* This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET 
   API reference when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq 
   for more information. If you do not wish to use NuGet, you can manually download 
   Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
   install it and then add its reference to this project. For any issues, questions or suggestions 
   please feel free to contact us using https://forum.aspose.com/c/email            
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/exceptions.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapMessageInfo.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Imap;

void ImapClientActivityLogging()
{
    System::String dataDir = GetDataDir_IMAP();
    
    // ExStart:ImapClientActivityLogging
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>(u"imap.gmail.com", 993, u"user@gmail.com", u"password");
    
    // Set security mode
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    
    try
    {
        // Get the message info collection
        System::SharedPtr<ImapMessageInfoCollection> list = client->ListMessages();
        
        // Download each message
        for (int32_t i = 0; i < list->get_Count(); i++)
        {
            // Save the EML file locally
            client->SaveMessage(list->idx_get(i)->get_UniqueId(), dataDir + list->idx_get(i)->get_UniqueId() + u".eml");
        }
    }
    catch (System::Exception& ex)
    {
        System::Console::WriteLine(ex->get_Message());
    }
    
    // ExEnd:ImapClientActivityLogging
}

