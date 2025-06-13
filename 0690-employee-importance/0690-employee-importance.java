/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        HashMap<Integer, Employee> mp = new HashMap<>();
        for(Employee e:employees){
            mp.put(e.id,e);
        }
        int result=0;
        Queue<Integer> q = new LinkedList<>();
        q.add(id);
        while(!q.isEmpty()){
            int eid = q.poll();
            Employee e = mp.get(eid);
            result+=e.importance;
            // process subordinates
            for(int subid: e.subordinates){
                q.add(subid);
            }
        }
        return result;
    }
}