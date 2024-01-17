/*문제 설명
수많은 마라톤 선수들이 마라톤에 참여하였습니다. 단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.

마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요.

제한사항
마라톤 경기에 참여한 선수의 수는 1명 이상 100,000명 이하입니다.
completion의 길이는 participant의 길이보다 1 작습니다.
참가자의 이름은 1개 이상 20개 이하의 알파벳 소문자로 이루어져 있습니다.
참가자 중에는 동명이인이 있을 수 있습니다.

입출력 예
participant	                                                completion	                                    return
["leo", "kiki", "eden"]	                                ["eden", "kiki"]	                                   "leo"
["marina", "josipa", "nikola", "vinko", "filipa"]	    ["josipa", "filipa", "marina", "nikola"]	        "vinko"
["mislav", "stanko", "mislav", "ana"]	                ["stanko", "ana", "mislav"]	"mislav"

입출력 예 설명
예제 #1
"leo"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #2
"vinko"는 참여자 명단에는 있지만, 완주자 명단에는 없기 때문에 완주하지 못했습니다.

예제 #3
"mislav"는 참여자 명단에는 두 명이 있지만, 완주자 명단에는 한 명밖에 없기 때문에 한명은 완주하지 못했습니다.

*/


function solution(participant, completion) {
    //해시 테이블은 키값에 문자열 가능
    //완주 체크용 해시 테이블 생성
    var hashmap = new Map();
    
    //마라톤 참여자 해시 테이블에 삽입(key: 참여자, value:1(동명이인 있을 때마다 +1)
    participant.forEach(value => {
        if (!hashmap.has(value)){
            hashmap.set(value, 1);
        } else {
            hashmap.set(value, hashmap.get(value) + 1);
        }
    })
    
    //해시 테이블에서 완주자 체크 후 key 값 -1, key값이 0되면 삭제 => 마지막에 남아있는 참여자가 완주 못 한 사람
    completion.forEach(value => {
        if(hashmap.has(value)) hashmap.set(value, hashmap.get(value)-1);
        if(hashmap.get(value) === 0) hashmap.delete(value);

    })
    const v = hashmap.keys()
    var answer = v.next().value;
    return answer;
}