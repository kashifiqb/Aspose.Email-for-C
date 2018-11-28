﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <Tools/Search/StringComparisonField.h>
#include <Tools/Search/MailQuery.h>
#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object_ext.h>
#include <system/object.h>
#include <system/iasyncresult.h>
#include <system/exceptions.h>
#include <system/environment.h>
#include <system/console.h>
#include <cstdint>
#include <Clients/SecurityOptions.h>
#include <Clients/Imap/Search/ImapQueryBuilder.h>
#include <Clients/Imap/ImapMessageInfoCollection.h>
#include <Clients/Imap/ImapClient/ImapClient.h>

#include "Examples.h"

using namespace Aspose::Email::Clients;
using namespace Aspose::Email::Clients::Imap;
using namespace Aspose::Email::Tools::Search;

void ListMessagesAsynchronously()
{
    // Create an instance of the ImapClient class
    System::SharedPtr<ImapClient> client = System::MakeObject<ImapClient>();
    
    // Specify host, username, password, port and SecurityOptions for your client
    client->set_Host(u"imap.gmail.com");
    client->set_Username(u"your.username@gmail.com");
    client->set_Password(u"your.password");
    client->set_Port(993);
    client->set_SecurityOptions(Aspose::Email::Clients::SecurityOptions::Auto);
    try
    {
        // ExStart:ListMessagesAsynchronouslyWithMailQuery
        System::SharedPtr<ImapQueryBuilder> builder = System::MakeObject<ImapQueryBuilder>();
        builder->get_Subject()->Contains(u"Subject");
        System::SharedPtr<MailQuery> query = builder->GetQuery();
        System::SharedPtr<System::IAsyncResult> asyncResult = client->BeginListMessages(query);
        System::SharedPtr<ImapMessageInfoCollection> messages = client->EndListMessages(asyncResult);
        // ExEnd:ListMessagesAsynchronouslyWithMailQuery
        
        System::Console::WriteLine(u"New Message Added Successfully");
        client->Dispose();
    }
    catch (System::Exception& ex)
    {
        System::Console::Write(System::Environment::get_NewLine() + System::ObjectExt::ToString(ex));
    }
    
}

