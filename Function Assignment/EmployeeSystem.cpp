class Employee {

    int id;
    string name;
    string department;
    bool working;
  
    bool isWorking() const { return working; }

    void terminateEmployee() { working = false; }
};


class IEmployeeStorage {
    virtual void saveToDatabase(const Employee& emp) = 0;
    virtual ~IEmployeeStorage() = default;
};


class EmployeeDatabaseStorage : public IEmployeeStorage {

    void saveToDatabase(const Employee& emp) override {}
};


class IReportGenerator {
    virtual void generateReport(const Employee& emp) = 0;
    virtual ~IReportGenerator() = default;
};


class XMLReportGenerator : public IReportGenerator {
    void generateReport(const Employee& emp) override {}
};


class CSVReportGenerator : public IReportGenerator {
    void generateReport(const Employee& emp) override {}
};


