﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from https://www.nuget.org/packages/Aspose.Email/, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using https://forum.aspose.com/c/email
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <MailMessage.h>
#include <AttachmentCollection.h>
#include <Attachment.h>

#include "Examples.h"

using namespace Aspose::Email;

void DisplayAttachmentFileName()
{
    System::String dataDir = GetDataDir_Email();
    System::SharedPtr<MailMessage> message = MailMessage::Load(dataDir + u"Attachments.eml");
    
    // ExStart:DisplayAttachmentFileName
    // Create a loop to display the no. of attachments present in email message
    
    {
        auto attachment_enumerator = (message->get_Attachments())->GetEnumerator();
        decltype(attachment_enumerator->get_Current()) attachment;
        while (attachment_enumerator->MoveNext() && (attachment = attachment_enumerator->get_Current(), true))
        {
            // Display the the attachment file name
            System::Console::WriteLine(attachment->get_Name());
        }
    }
    // ExEnd:DisplayAttachmentFileName
}






