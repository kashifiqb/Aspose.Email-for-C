﻿/*
This project uses Automatic Package Restore feature of NuGet to resolve Aspose.Email for .NET API reference 
when the project is build. Please check https://Docs.nuget.org/consume/nuget-faq for more information. 
If you do not wish to use NuGet, you can manually download Aspose.Email for .NET API from http://www.aspose.com/downloads, 
install it and then add its reference to this project. For any issues, questions or suggestions 
please feel free to contact us using http://www.aspose.com/community/forums/default.aspx
*/

#include <system/string.h>
#include <system/shared_ptr.h>
#include <system/object.h>
#include <system/console.h>
#include <system/collections/ienumerator.h>
#include <Mail/MimeParts/AttachmentCollection.h>
#include <Mail/MimeParts/Attachment.h>
#include <Mail/MailMessage/MailMessage.h>
#include <Mail/MailMessage/LoadOptions/MsgLoadOptions.h>

#include "Examples.h"


using namespace Aspose::Email::Mail;


void ExtractEmbeddedObjectsFromEmail()
{
    // ExStart:ExtractEmbeddedObjectsFromEmail
    // The path to the File directory.
    System::String dataDir = GetDataDir_Email();
    
    // Create an instance of MailMessage and load an email file
    System::SharedPtr<MailMessage> mailMsg = MailMessage::Load(dataDir + L"Message.msg", System::MakeObject<MsgLoadOptions>());
    
    
    {
        auto attachment_enumerator = (mailMsg->get_Attachments())->GetEnumerator();
        decltype(attachment_enumerator->get_Current()) attachment;
        while (attachment_enumerator->MoveNext() && (attachment = attachment_enumerator->get_Current(), true))
        {
            // To display the the attachment file name
            attachment->Save(dataDir + L"MessageEmbedded_out.msg");
            
            System::Console::WriteLine(attachment->get_Name());
        }
    }
    // ExEnd:ExtractEmbeddedObjectsFromEmail
}






