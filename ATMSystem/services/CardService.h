#pragma once
#include "../interfaces/ICardService.h"
#include "../interfaces/ICard.h"
#include "../exceptions/Exceptions.h"

class CardService : public ICardService{
    ICard& card;

public:
    CardService(ICard& card) : card(card) {}

    void validatePIN(const std::string& enteredPIN) {
        try {
            card.validatePIN(enteredPIN);
        } catch (const CardBlockedException& e) {
            throw CardBlockedException();  
        } catch (const InvalidPINException& e) {
            throw InvalidPINException(); 
        }
    }
};
