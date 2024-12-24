#include <iostream>
#include <string>

const double inboxEmailCarbonAmountPerKg = 0.02;
const double sentEmailCarbonAmountPerKg = 0.05;
const double spamEmailCarbonAmountPerKg = 0.03;

enum EmailType
{
    inbox,
    sent,
    spam
};

struct Email
{
    std::string emailId = "";
    std::string emailSource = "";
    int inboxFolderSize = 0;
    int sentFolderSize = 0;
    int spamFolderSize = 0;
};

struct EmailCarbonFootprint
{
    double inboxFolderCarbonAmount = 0;
    double sentFolderCarbonAmount = 0;
    double spamFolderCarbonAmount = 0;
};

double calculateEmailCarbonAmount(int emailFolderSize, EmailType emailType)
{
    switch (emailType)
    {
    case inbox:
        return inboxEmailCarbonAmountPerKg * emailFolderSize;
    case sent:
        return sentEmailCarbonAmountPerKg * emailFolderSize;
    case spam:
        return spamEmailCarbonAmountPerKg * emailFolderSize;
    default:
        return 0;
    }
}

EmailCarbonFootprint getEmailCarbonFootprint(const std::string &mailSource, const Email &email)
{
    EmailCarbonFootprint emailCarbonFootprint;
    if (mailSource == "gmail")
    {
        emailCarbonFootprint.inboxFolderCarbonAmount = calculateEmailCarbonAmount(email.inboxFolderSize, inbox);
        emailCarbonFootprint.sentFolderCarbonAmount = calculateEmailCarbonAmount(email.sentFolderSize, sent);
        emailCarbonFootprint.spamFolderCarbonAmount = calculateEmailCarbonAmount(email.spamFolderSize, spam);
    }

    return emailCarbonFootprint;
}

void displayEmailCarbonFootprint(EmailCarbonFootprint &emailCarbonFootprint, Email &email)
{
    std::cout << email.emailSource << std::endl;
    std::cout << "emailId : " << email.emailId << std::endl;
    std::cout << "source: " << email.emailSource << std::endl;
    std::cout << "inbox : " << emailCarbonFootprint.inboxFolderCarbonAmount << " KG" << std::endl;
    std::cout << "sent : " << emailCarbonFootprint.sentFolderCarbonAmount << " KG" << std::endl;
    std::cout << "spam : " << emailCarbonFootprint.spamFolderCarbonAmount << " KG" << std::endl;
}

int main()
{
    Email email = {
        "priyansh.soni@gmail.com",
        "gmail",
        50,
        5,
        1};

    EmailCarbonFootprint emailCarbonFootprint = getEmailCarbonFootprint("gmail", email);

    displayEmailCarbonFootprint(emailCarbonFootprint, email);

    return 0;
}