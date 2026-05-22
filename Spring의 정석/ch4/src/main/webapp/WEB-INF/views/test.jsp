<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
    <script src="https://code.jquery.com/jquery-1.11.3.js"></script>
</head>
<br>
<h2>commentTest</h2>
comment: <input type="text" name="comment"><br>
<button id="sendBtn" type="button">SEND</button>
<button id="modBtn" type="button">수정</button>

<div id="commentList"></div>
<div id="replyForm" style="display: none">
    <input type="text" name="replyComment">
    <button id="wrtRepBtn" type="button">등록</button>
</div>
<script>
    let bno = 618;

    let showList = function(bno) {
        $.ajax({
            type:'GET',       // 요청 메서드
            url: '/ch4/comments?bno='+bno,  // 요청 URI
            success : function(result){ // result: 배열
                $("#commentList").html(toHTML(result));    // 서버로부터 응답이 도착하면 호출될 함수
            },
            error   : function(){ alert("error") } // 에러가 발생했을 때, 호출될 함수
        }); // $.ajax()
    }

    $(document).ready(function(){
        showList(bno);

        $("#modBtn").click(function(){
            let cno = $(this).attr("data-cno");
            let comment = $("input[name=comment]").val();

            if(comment.trim()=='') {
                alert('댓글을 입력해주세요.');
                $("input[name=comment]").focus();
                return;
            }

            $.ajax({
                type:'PATCH',       // 요청 메서드
                url: '/ch4/comments/'+cno,  // 요청 URI: /ch4/comments/70   PATCH
                headers : { "content-type": "application/json"}, // 요청 헤더
                data : JSON.stringify({cno:cno, comment:comment}),  // 서버로 전송할 데이터. stringify()로 직렬화 필요.
                success : function(result) {
                    alert(result);
                    showList(bno);
                },
                error   : function(){ alert("error") } // 에러가 발생했을 때, 호출될 함수
            }); // $.ajax()
        });

        $("#wrtRepBtn").click(function(){
            let comment = $("input[name=replyComment]").val();
            let pcno = $("#replyForm").parent().attr("data-pcno");

            if(comment.trim()=='') {
                alert('댓글을 입력해주세요.');
                $("input[name=replyComment]").focus();
                return;
            }

            $.ajax({
                type:'POST',       // 요청 메서드
                url: '/ch4/comments?bno='+bno,  // 요청 URI: /ch4/comments?bno=1085
                headers : { "content-type": "application/json"}, // 요청 헤더
                data : JSON.stringify({pcno:pcno, bno:bno, comment:comment}),  // 서버로 전송할 데이터. stringify()로 직렬화 필요.
                success : function(result) {
                    alert(result);
                    showList(bno);
                },
                error   : function(){ alert("error") } // 에러가 발생했을 때, 호출될 함수
            }); // $.ajax()

            $("#replyForm").css("display", "none");
            $("input[name=replyComment]").val('');
            $("#replyForm").appendTo("body");
        });

        $("#sendBtn").click(function(){
            let comment = $("input[name=comment]").val();

            if(comment.trim()=='') {
                alert('댓글을 입력해주세요.');
                $("input[name=comment]").focus();
                return;
            }

            $.ajax({
                type:'POST',       // 요청 메서드
                url: '/ch4/comments?bno='+bno,  // 요청 URI: /ch4/comments?bno=1085
                headers : { "content-type": "application/json"}, // 요청 헤더
                data : JSON.stringify({bno:bno, comment:comment}),  // 서버로 전송할 데이터. stringify()로 직렬화 필요.
                success : function(result) {
                    alert(result);
                    showList(bno);
                },
                error   : function(){ alert("error") } // 에러가 발생했을 때, 호출될 함수
            }); // $.ajax()
        });

        $("#commentList").on("click", ".modBtn", function() {
            let cno = $(this).parent().attr("data-cno");
            let comment = $("span.comment", $(this).parent()).text(); // $(this): 버튼, $(this).parent(): li태그

            // 1. comment의 내용을 input에 뿌려주기
            $("input[name=comment]").val(comment);
            // 2. cno 전달하기
            $("#modBtn").attr("data-cno", cno);
        });

        $("#commentList").on("click", ".replyBtn", function() {
            // 1. replyForm을 옮기고
            $("#replyForm").appendTo($(this).parent());

            // 2. 답글을 입력할 폼을 보여준다
            $("#replyForm").css("display", "block");
        });

        // $(".delBtn").click(function() { 비동기 방식이기에 이 시점에는 아직 delBtn이 만들어지지 않았음
        $("#commentList").on("click", ".delBtn", function() {
            let cno = $(this).parent().attr("data-cno");
            let bno = $(this).parent().attr("data-bno");

            $.ajax({
                type:'DELETE',       // 요청 메서드
                url: '/ch4/comments/'+cno+'?bno='+bno,  // 요청 URI
                success : function(result){ // result: 배열
                    alert(result);
                    showList(bno);
                },
                error   : function(){ alert("error") } // 에러가 발생했을 때, 호출될 함수
            }); // $.ajax()
        });
    });

    let toHTML = function (comments) { // comments(result): 배열
        let tmp = "<url>";

        comments.forEach(function (comment) { // comment: 각 comment 객체
            tmp += '<li data-cno='+ comment.cno;
            tmp += ' data-pcno='+comment.pcno;
            tmp += ' data-bno='+comment.bno + '>';
            if(comment.cno!=comment.pcno){
                tmp += 'ㄴ';
            }
            tmp += ' commenter=<span class="commenter">'+comment.commenter+'</span>';
            tmp += ' comment=<span class="comment">'+comment.comment +'</span>';
            tmp += ' up_date'+comment.up_date;
            tmp += '<button class="delBtn">삭제</button>';
            tmp += '<button class="modBtn">수정</button>';
            tmp += '<button class="replyBtn">답글</button>';
            tmp += '</li>';
        })

        return tmp+"</url>";
    }
</script>
</body>
</html>
