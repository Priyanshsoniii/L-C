using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

public interface ICustomerFilter
{
    List<Customer> Filter(List<Customer> customerList, string criteria);
}

public class CustomerByCountryFilter : ICustomerFilter
{
    public List<Customer> Filter(List<Customer> customerList, string country)
    {
        return customerList.Where(customer => customer.Country.Contains(country))
                           .OrderBy(customer => customer.Id)
                           .ToList();
    }
}

public class CustomerByCompanyFilter : ICustomerFilter
{
    public List<Customer> Filter(List<Customer> customerList, string company)
    {
        return customerList.Where(customer => customer.Company.Contains(company))
                           .OrderBy(customer => customer.Id)
                           .ToList();
    }
}

public class CustomerByContactPersonFilter : ICustomerFilter
{
    public List<Customer> Filter(List<Customer> customerList, string contactPerson)
    {
        return customerList.Where(customer => customer.ContactPerson.Contains(contactPerson))
                           .OrderBy(customer => customer.Id)
                           .ToList();
    }
}

public class CustomerRepository
{
    private List<Customer> customerDatabase;

    public CustomerRepository(List<Customer> customerList)
    {
        customerDatabase = customerList;
    }

    public List<Customer> GetCustomers(ICustomerFilter filter, string criteria)
    {
        return filter.Filter(customerDatabase, criteria);
    }
}

public class CsvExporter
{
    public string ConvertCustomersToCsv(List<Customer> customerList)
    {
        StringBuilder csvContent = new StringBuilder();
        csvContent.AppendLine("CustomerID,Company,ContactPerson,Country");

        foreach (var customer in customerList)
        {
            csvContent.AppendFormat("{0},{1},{2},{3}", 
                customer.Id, customer.Company, customer.ContactPerson, customer.Country);
            csvContent.AppendLine();
        }

        return csvContent.ToString();
    }
}
