/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    HashMap<Integer, Employee> mp = new HashMap<>();
    int result=0;
    private void recurImp(List<Employee> employees, int id){
        // base

        // logic
        Employee e = mp.get(id);
        result+=e.importance;
        for(int subid: e.subordinates){
            recurImp(employees,subid);
        }
    }
    public int getImportance(List<Employee> employees, int id) {
        for(Employee e:employees){
            mp.put(e.id,e);
        }
        recurImp(employees,id);
        return result;
    }
}