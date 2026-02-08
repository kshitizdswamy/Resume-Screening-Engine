# Resume Screening Engine (C++)
A backend resume screening engine built in C++ that evaluates a candidate’s resume against job requirements.

# Features
- Reads resume and job description from text files
- Extracts predefined skills
- Applies weighted and capped scoring to avoid keyword stuffing
- Identifies matched and missing skills
- Outputs a final hiring decision

# How It Works
1. Resume and job description are read as text files
2. Skills are extracted using basic text parsing
3. Only skills required by the job are evaluated
4. A score is calculated based on predefined weights
5. The system outputs a decision: GOOD, BORDERLINE, or REJECT

# Future Improvements
- PDF/DOC resume parsing
- Web interface integration
- Advanced NLP-based matching

